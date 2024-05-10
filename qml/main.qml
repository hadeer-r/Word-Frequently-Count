import QtQuick
import QtQuick.Controls
import QtCore
import QtQuick.Layouts
import Qt.labs.settings
import QtQuick 6.5
import QtQuick.Controls 6.5
//import UntitledProject4

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
              source: "qrc:/submit.png"
              fillMode: Image.PreserveAspectFit
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
              source: "qrc:/Path.png"
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
          source: "qrc:/Vector.png"
          fillMode: Image.PreserveAspectFit
      }
  }

  Button {
      id: historybutton
      x: 1085
      y: 89
      width: 71
      height: 54
      text: qsTr("")
      autoRepeat: true
      checkable: false
      flat: true

      Image {
          id: history
          x: 20
          y: 5
          source: "qrc:/History.png"
          fillMode: Image.PreserveAspectFit
      }
  }

// states: [
  //     State {
  //         name: "clicked"
  //     }
  // ]


  // Settings {
  //     category: 'window'
  //     property alias x: window.x
  //     property alias y: window.x
  //     property alias width: window.width
  //     property alias height: window.height
  // }





}
