import QtQuick 2.6
import QtQuick.Window 2.2
import QtCharts 2.2

import elmaven.core.eic 1.0


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ChartView {
        title: "Spline"
        anchors.fill: parent
        antialiasing: false
        function loadData() {
            console.debug("loading data")
            console.debug(intensities)
            for(var i=0; i<intensities.length; i+=1) {
                console.debug(rts[i], " : ",  intensities[i])
                splinePlot.append(rts[i], intensities[i])
            }
        }
        EIC {
            id: eic
        }

        property var intensities: eic.intensities
        property var rts: eic.rts

        Component.onCompleted: {
            loadData();
        }
        ValueAxis {
            id: xAxis
            min: 0
            max: 45
            tickCount: 10
       }
       ValueAxis {
            id: yAxis
            min: 0
            max: 45
            tickCount: 10
       }
       SplineSeries {
           id: splinePlot
           axisX: xAxis
           axisY: yAxis
      }

    }
}
