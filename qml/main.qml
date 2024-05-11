import QtQuick
import QtQuick.Controls
import QtCore
import QtQuick.Layouts
import Qt.labs.settings
import QtQuick 6.5
import QtQuick.Controls 6.5
import Word_Frequently_Count

Window {
  width: 1200
  height: 700
  minimumWidth: 1200
  minimumHeight: 700
  visible: true
  title: qsTr("Word_Frequently_Count")
  color:"#e6a7fc"

  // color: "#e6a7fc"
  // radius: 3
  // border.color: "#fafafa"
  // border.width: 1
  // activeFocusOnTab: false
  // focus: false

  Backend {
      id: myBackend
      onGetTextFromFileEmitted : (text) => {
                                     textArea.text=text
                                 }
      onUpdateTextUserEmitted : (path,paragraph) =>{
                             textArea.text=paragraph
                         }
      onSortFrequencyEmitted : (currentSort) =>{
                                   textArea1.text=currentSort
                               }
      onRankWordsEmitted : (currentRank) => {
                               textArea1.text=currentRank
                           }
      onAutoCompletionWorddsEmitted : (paragraph) =>{
                                          textArea.text=paragraph
                                      }
      onSearchWordEmitted : (freq)=>{
                                textField1.text=freq
                            }
  }

  Rectangle {
      id: input
      x: 48
      y: 147
      width: 517
      height: 406
      color: "#ffffff"
      radius: 12
      border.color: "#b662d4"
      border.width: 3

      ScrollView {
          id: scrollView
          x: 8
          y: 13
          width: 501
          height: 385

          TextArea {
              id: textArea
              x: 0
              y: -7
              width: 487
              height: 380
              font.pointSize: 12
              placeholderText: qsTr("Paste or type your data here...")

              onTextChanged: {
                  var var_path = textField.text
                  if(var_path===""){
                      myBackend.updateTextUser("",textArea.text)
                  } else {
                      myBackend.updateTextUser(var_path,textArea.text)
                  }
                  if(rank.checked===false){
                      myBackend.sortFrequency(textArea1.text,textArea.text)
                  } else {
                      myBackend.rankWords(textArea1.text,textArea.text)
                  }


              }


          }
      }

      Button {
          id: submitbutton
          x: 196
          y: 412
          width: 125
          height: 127
          visible: true
          autoRepeat: true
          flat: true
          checkable: true
          display: AbstractButton.IconOnly

          Image {
              id: submit
              x: 17
              y: 6
              width: 91
              height: 116
              source: "../qrc/submit.png"
              fillMode: Image.PreserveAspectFit
          }
          onClicked: {
              var userInputPath=textField.text;
              if(textField.text!==""){
                  myBackend.getTextFromFile(userInputPath)
              }

          }
      }

      Text {
          id: text1
          x: 0
          y: -51
          color: "#ffffff"
          text: qsTr("Input")
          font.pixelSize: 36
          font.styleName: "Semibold"
      }
  }

  Rectangle {
      id: output
      x: 634
      y: 147
      width: 517
      height: 406
      color: "#ffffff"
      radius: 12
      border.color: "#b662d4"
      border.width: 3

      Text {
          id: text2
          x: 8
          y: -57
          color: "#ffffff"
          text: qsTr("Output")
          font.pixelSize: 32
          font.styleName: "Semibold"
      }

      ScrollView {
          id: scrollView1
          x: 8
          y: 8
          width: 372
          height: 390

          TextArea {
              id: textArea1
              x: 6
              y: 9
              width: 343
              height: 363
              placeholderText: qsTr("")
          }
      }

      Switch {
          id: rank
          x: 386
          y: 17
          width: 114
          height: 40
          text: qsTr("Rank")
          checked: false
          onCheckedChanged: {
              if(checked===false){
                  myBackend.sortFrequency(textArea1.text,textArea.text)
              } else {
                  myBackend.rankWords(textArea1.text,textArea.text)
              }

          }
      }
  }


  Rectangle {
      id: upload
      x: 233
      y: 89
      width: 321
      height: 52
      color: "#ffffff"
      radius: 6
      border.color: "#b662d4"
      border.width: 2

      TextField {
          id: textField
          x: 55
          y: 6
          width: 258
          height: 40
          font.pointSize: 11
          placeholderText: qsTr("Enter your path here")

          Image {
              id: path
              x: -48
              y: 4
              width: 45
              height: 32
              source: "../qrc/Path.png"
              fillMode: Image.PreserveAspectFit
          }
      }
  }

  Rectangle {
      id: searchfield
      x: 788
      y: 89
      width: 297
      height: 52
      color: "#ffffff"
      radius: 6
      border.color: "#b662d4"
      border.width: 2

      TextField {
          id: textField1
          x: 49
          y: 6
          width: 240
          height: 40
          font.pointSize: 11
          placeholderText: qsTr("Search..")
      }

      Image {
          id: vector
          x: 12
          y: 13
          source: "../qrc/Vector.png"
          fillMode: Image.PreserveAspectFit
      }
  }

  Button {
      id: searchWordbutton
      x: 1085
      y: 89
      width: 71
      height: 54
      text: qsTr("")
      autoRepeat: true
      checkable: false
      flat: true

      Image {
          id: searchWords
          width: parent.width
          height: parent.height
          x: 20
          y: 5
          source: "../qrc/SearchWord.png"
          fillMode: Image.PreserveAspectFit
      }
      onClicked: {
          myBackend.searchWord(textField1.text)
      }
  }

  // Button {
  //     id: nextWord
  //     x: 200
  //     y: 595
  //     width: 30
  //     height: 30
  //     text: qsTr("")
  //     autoRepeat: true
  //     checkable: false
  //     flat: true

  //     Image {
  //         id: right
  //         width: 20
  //         height: 20
  //         x: 11
  //         y: 5
  //         source: "../qrc/right.png"
  //         fillMode: Image.PreserveAspectFit
  //     }
  //     onClicked: {
  //         suggesstions.next=0
  //         myBackend.autoCompletionWordds(textArea.text,suggesstions.idx,suggesstions.next)
  //     }
  // }

  // Button {
  //         id: previousWord
  //         x: 25
  //         y: 595
  //         width: 30
  //         height: 30
  //         text: qsTr("")
  //         autoRepeat: true
  //         checkable: false
  //         flat: true

  //         Image {
  //             id: left
  //             width: 20
  //             height: 20
  //             x: 12
  //             y: 5
  //             source: "../qrc/left.png"
  //             fillMode: Image.PreserveAspectFit
  //       }
  //        onClicked: {
  //            suggesstions.next=1
  //            myBackend.autoCompletionWordds(textArea.text,suggesstions.idx,suggesstions.next)
  //        }
  // }

  Rectangle {
          id: suggesstions
          width: 140
          height: 40
          radius: 3
          y : 595
          x : 60
          border.color: "#b662d4"
          border.width: 1
          color: "white"

          property  int idx: 0
          property int next: 0


          Button {
              id: autocom
              width: parent.width
              height: parent.height
              Text {
                  id: word
                  width: parent.width
                  height: parent.height
                  color: "black"
                  text: qsTr("Complete Your Word")
              }
              onClicked : myBackend.autoCompletionWordds(textArea.text)

          }

        }




}
