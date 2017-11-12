import QtQuick 2.0

Item {
    width: 1280
    height: 720

    MouseArea{
        onClicked: {}
        onReleased: {}
    }
    onVisibleChanged: {
        if(visible){
            translator();
        }
    }

    Component.onCompleted: {
        I108n.languageChanged.connect(translator)
        translator()
    }

    function translator() {
        if(I108n.lang == "en")
            englishPage.visible = true;
        else
            englishPage.visible = false;
    }


    //中文页
    Item {
        width: 1280
        height: 720

        Image {
            id: main_bkg_CN
            anchors.fill: parent;
            source: "../Assistantimages/bg.png"
            visible:true;
        }

        Loader {
            width: 67;
            height: 67;
            source: "Button.qml"
            anchors.left: parent.left;
            anchors.leftMargin: 66;
            anchors.top: parent.top;
            anchors.topMargin: 20;
            onLoaded: {
                item.normalSource = "../Assistantimages/back_icon_n.png";
                item.pressSource = "../Assistantimages/back_icon_p.png";
                item.clicked.connect(helpPageBackClicked);
            }
        }

        Text {
            id:title_CN
            text:"连接帮助";
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: parent.top;
            anchors.topMargin: 32;
            font.pixelSize: 36;
            font.family: fontFamily;
            color: "#ffffff";
            wrapMode: Text.Wrap;
        }

        Rectangle {
            width: 1199;
            height: 579;
            y:104;
            anchors.bottom: main_bkg_CN.bottom;
            anchors.bottomMargin: 35;
            anchors.horizontalCenter:main_bkg_CN.horizontalCenter;

            Image {
                id: listview_bkg_CN
                anchors.fill: parent
                source: "../Assistantimages/center.png"
            }

            ListView{
                id: listPage
                width: 1199
                height: 579
                anchors.fill: parent
                anchors.bottomMargin: 1
                anchors.topMargin: 1
                model: changePageModel
                clip: true
                VisualItemModel {
                    id: changePageModel
                    Item {
                        id:item1
                        width: 1199
                        height: 284

                        Image {
                            anchors.right: remind1.left
                            anchors.rightMargin: 35
                            anchors.top: parent.top
                            anchors.topMargin: 66
                            source: "../Assistantimages/title_bg.png"
                        }

                        Text {
                            id:remind1
                            anchors.top: parent.top
                            anchors.topMargin: 66
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            text: qsTr("一：请扫描主页面二维码下载并安装萌驾APP!");
                        }
                        Text {
                            id:remind1_child1
                            anchors.top: remind1.bottom
                            anchors.topMargin: 35
                            anchors.left: parent.left
                            anchors.leftMargin: 160
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: qsTr("①若完成，请查看下一条");
                        }
                        Text {
                            anchors.top: remind1_child1.bottom
                            anchors.topMargin: 35
                            anchors.left: parent.left
                            anchors.leftMargin: 160
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: qsTr("②若未完成，请返回二维码界面，进行扫描下载");
                        }
                    }

                    Item {
                        id:item2
                        width: 1199
                        height: 472

                        Image {
                            anchors.right: remind2.left
                            anchors.rightMargin: 35
                            anchors.top: parent.top
                            source: "../Assistantimages/title_bg.png"
                        }

                        Text {
                            id:remind2
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            text: qsTr("二：绑定你的专属车型,体验更优质服务,操作如下:");
                        }
                        Text {
                            id:remind2_child
                            anchors.top: remind2.bottom
                            anchors.topMargin: 30
                            anchors.left: parent.left
                            anchors.leftMargin: 160
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: qsTr("首次进入萌驾APP 一 我的车 一 扫描车机二维码定位您的车型");
                        }

                        Image {
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            anchors.top: remind2_child.bottom
                            anchors.topMargin: 60
                            source: "../Assistantimages/barcode/pic4.png"
                        }

                        Image {
                            anchors.right: parent.right
                            anchors.rightMargin: 120
                            anchors.top: remind2_child.bottom
                            anchors.topMargin: 60
                            source: "../Assistantimages/barcode/pic5.png"
                        }
                    }

                    Item {
                        id:item3
                        width: 1199
                        height: 547

                        Image {
                            anchors.right: remind3.left
                            anchors.rightMargin: 35
                            anchors.top: parent.top
                            source: "../Assistantimages/title_bg.png"
                        }

                        Text {
                            id:remind3
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            text: qsTr("三：使用镜像功能，请开启开发者选项并勾选USB调试");
                        }
                        Text {
                            id:remind3_child
                            anchors.top: remind3.bottom
                            anchors.topMargin: 35
                            anchors.left: parent.left
                            anchors.leftMargin: 160
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: qsTr("开启开发者选项，勾选默认<font color=\"#ff3057\">USB配件</font>并确认");
                        }

                        Image {
                            anchors.left: parent.left
                            anchors.leftMargin: 176
                            anchors.top: remind3_child.bottom
                            anchors.topMargin: 60
                            source: "../Assistantimages/barcode/pic3.png"
                        }
                    }

                    Item {
                        id:item4
                        width: 1199
                        height: 588

                        Image {
                            anchors.right: remind4.left
                            anchors.rightMargin: 35
                            anchors.top: parent.top
                            source: "../Assistantimages/title_bg.png"
                        }

                        Text {
                            id:remind4
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            text: qsTr("四：开启设备允许运行权限");
                        }
                        Text {
                            id:remind4_child1
                            width: 450
                            anchors.top: remind4.bottom
                            anchors.topMargin: 35
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            wrapMode: Text.WordWrap
                            text: qsTr("①首次连接时<font color=\"#ff3057\">始终允许该软件运行权限</font>若如[帮助三]中所示，已开启USB调试，则此设置不显示");
                        }

                        Text {
                            id:remind4_child2
                            width: 478
                            anchors.top: remind4.bottom
                            anchors.topMargin: 35
                            anchors.left: remind4_child1.right
                            anchors.leftMargin: 98
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            wrapMode: Text.WordWrap
                            text: qsTr("②对应显示此类权限信息，请<font color=\"#ff3057\">勾选并允许</font>，帮助你体验更优质服务");
                        }

                        Image {
                            anchors.left: parent.left
                            anchors.leftMargin: 140
                            anchors.top: remind4_child1.bottom
                            anchors.topMargin: 65
                            source: "../Assistantimages/barcode/pic10.png"
                        }

                        Image {
                            anchors.right: parent.right
                            anchors.rightMargin: 102
                            anchors.top: remind4_child2.bottom
                            anchors.topMargin: 125
                            source: "../Assistantimages/barcode/pic9.png"
                        }

                    }

                    Item {
                        id:item5
                        width: 1199
                        height: 484

                        Image {
                            anchors.right: remind5.left
                            anchors.rightMargin: 35
                            anchors.top: parent.top
                            source: "../Assistantimages/title_bg.png"
                        }

                        Text {
                            id:remind5
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            text: qsTr("五：允许USB调试（若如[帮助三]USB调试已开启，此时设置不显示）");
                        }
                        Text {
                            id:remind5_child
                            anchors.top: remind5.bottom
                            anchors.topMargin: 35
                            anchors.left: parent.left
                            anchors.leftMargin: 160
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: qsTr("首次连接时勾选<font color=\"#ff3057\">始终允许该PC</font>并确定");
                        }

                        Image {
                            anchors.left: parent.left
                            anchors.leftMargin: 158
                            anchors.top: remind5_child.bottom
                            anchors.topMargin: 54
                            source: "../Assistantimages/barcode/pic8.png"
                        }
                    }

                    Item {
                        id:item6
                        width: 1199
                        height: 384

                        Image {
                            anchors.right: remind6.left
                            anchors.rightMargin: 35
                            anchors.top: parent.top
                            source: "../Assistantimages/title_bg.png"
                        }

                        Text {
                            id:remind6
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            text: qsTr("六：连接失败请尝试<font color=\"#ff3057\">重新</font>连接USB，或<font color=\"#ff3057\">重启</font>手机");
                        }
                        Text {
                            id:remind6_child1
                            anchors.top: remind6.bottom
                            anchors.topMargin: 35
                            anchors.left: parent.left
                            anchors.leftMargin: 160
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: qsTr("①重新拔插USB，尝试重新连接");
                        }
                        Text {
                            id:remind6_child2
                            anchors.top: remind6.bottom
                            anchors.topMargin: 35
                            anchors.left: remind6_child1.right
                            anchors.leftMargin: 275
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: qsTr("②重启手机");
                        }

                        Image {
                            anchors.left: parent.left
                            anchors.leftMargin: 178
                            anchors.top: remind6_child1.bottom
                            anchors.topMargin: 68
                            source: "../Assistantimages/barcode/pic6.png"
                        }

                        Image {
                            anchors.right: parent.right
                            anchors.rightMargin: 178
                            anchors.top: remind6_child2.bottom
                            anchors.topMargin: 68
                            source: "../Assistantimages/barcode/pic7.png"
                        }

                    }
                }

            }
        }
    }



    //英文页
    Item {
        id: englishPage
        width: 1280
        height: 720
        //visible: I108n.lang == "en" ? ture : false;

        Image {
            id: main_bkg_en
            anchors.fill: parent;
            source: "../Assistantimages/bg.png"
            visible:true;
        }

        Loader {
            width: 67;
            height: 67;
            source: "Button.qml"
            anchors.left: parent.left;
            anchors.leftMargin: 66;
            anchors.top: parent.top;
            anchors.topMargin: 20;
            onLoaded: {
                item.normalSource = "../Assistantimages/back_icon_n.png";
                item.pressSource = "../Assistantimages/back_icon_p.png";
                item.clicked.connect(helpPageBackClicked);
            }
        }

        Text {
            id:title_en
            text:"Connection help"
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.top: parent.top;
            anchors.topMargin: 32;
            font.pixelSize: 36;
            font.family: fontFamily;
            color: "#ffffff";
            wrapMode: Text.Wrap;
        }

        Rectangle {
            width: 1199;
            height: 579;
            y:104;
            anchors.bottom: main_bkg_en.bottom;
            anchors.bottomMargin: 35;
            anchors.horizontalCenter:main_bkg_en.horizontalCenter;

            Image {
                id: listview_bkg_en
                anchors.fill: parent
                source: "../Assistantimages/center.png"
            }

            ListView{
                id: listPage_en
                width: 1199
                height: 579
                anchors.fill: parent
                anchors.bottomMargin: 1
                anchors.topMargin: 1
                model: changePageModel_en
                clip: true
                VisualItemModel {
                    id: changePageModel_en
                    Item {
                        id:item1_en
                        width: 1199
                        height: 252 //381

                        Image {
                            anchors.right: remind1_en.left
                            anchors.rightMargin: 35
                            anchors.top: parent.top
                            anchors.topMargin: 66
                            source: "../Assistantimages/title_bg.png"
                        }

                        Text {
                            id:remind1_en
                            anchors.top: parent.top
                            anchors.topMargin: 66
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            text: "First：";
                            //qsTr("一：请扫描主页面二维码下载并安装萌驾APP!");
                        }
                        Text {
                            id:remind1_en_half
                            anchors.top: remind1_en.top
                            anchors.left: parent.left
                            anchors.leftMargin: 248
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            width: 831;
                            wrapMode: Text.WordWrap;
                            text: "Please Scan QR code to download and install QDrive APP at homepage";
                            //qsTr("一：请扫描主页面二维码下载并安装萌驾APP!");
                        }
                        Text {
                            id:remind1_en_child1
                            anchors.top: remind1_en_half.bottom
                            anchors.topMargin: 6
                            anchors.left: parent.left
                            anchors.leftMargin: 248
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "①If you finish，please move to the second prompt.";
                            //qsTr("①若完成，请查看下一条");
                        }
                        Text {
                            id:remind1_en_child2
                            anchors.top: remind1_en_child1.bottom
                            anchors.topMargin: 6
                            anchors.left: parent.left
                            anchors.leftMargin: 248
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "②If not，please rescan QR code at homepage.";
                            //qsTr("②若未完成，请返回二维码界面，进行扫描下载");
                        }

                    }

                    Item {
                        id:item2_en
                        width: 1199
                        height: 550

                        Image {
                            anchors.right: remind2_en.left
                            anchors.rightMargin: 35
                            anchors.top: parent.top
                            source: "../Assistantimages/title_bg.png"
                        }

                        Text {
                            id:remind2_en
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            text: "Second：Binding your exclusive vehicle models and getting more "
                            //qsTr("二：绑定你的专属车型,体验更优质服务,操作如下:");
                        }
                        Text {
                            id:remind2_en_half
                            anchors.top: remind2_en.bottom
                            anchors.topMargin: 6
                            anchors.left: parent.left
                            anchors.leftMargin: 248
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            width: 815;
                            wrapMode: Text.WordWrap;
                            text: "quality services，Operating as follows :"
                            //qsTr("二：绑定你的专属车型,体验更优质服务,操作如下:");
                        }
                        Text {
                            id:remind2_en_child
                            anchors.top: remind2_en_half.bottom
                            anchors.topMargin: 6
                            anchors.left: parent.left
                            anchors.leftMargin: 248
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            width: 815;
                            wrapMode: Text.WordWrap;
                            text: "First connection with Qdrive --- My car---Scan vehicle QR code to match your car."
                            //qsTr("首次进入萌驾APP 一 我的车 一 扫描车机二维码定位您的车型");
                        }

                        Image {
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            anchors.top: remind2_en_child.bottom
                            anchors.topMargin: 60
                            source: "../Assistantimages/barcode/pic4.png"
                        }

                        Image {
                            anchors.right: parent.right
                            anchors.rightMargin: 120
                            anchors.top: remind2_en_child.bottom
                            anchors.topMargin: 60
                            source: "../Assistantimages/barcode/pic5.png"
                        }
                    }

                    Item {
                        id:item3_en
                        width: 1199
                        height: 600

                        Image {
                            anchors.right: remind3_en.left
                            anchors.rightMargin: 35
                            anchors.top: parent.top
                            source: "../Assistantimages/title_bg.png"
                        }

                        Text {
                            id:remind3_en
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            width: 1010;
                            wrapMode: Text.WordWrap;
                            text: "Third：Using mirror function，please open developer option and check ";
                            //text: qsTr("三：使用镜像功能，请开启开发者选项并勾选USB调试");
                        }

                        Text {
                            id:remind3_en_half
                            anchors.top: remind3_en.bottom
                            anchors.topMargin: 6
                            anchors.left: parent.left
                            anchors.leftMargin: 215
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "the USB debugging.";
                            //text: qsTr("三：使用镜像功能，请开启开发者选项并勾选USB调试");
                        }

                        Text {
                            id:remind3_en_child
                            anchors.top: remind3_en_half.bottom
                            anchors.topMargin: 6
                            anchors.left: parent.left
                            anchors.leftMargin: 215
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "Open developer option，check the USB debugging and determine.";
                            //text: qsTr("开启开发者选项，勾选默认<font color=\"#ff3057\">USB配件</font>并确认");
                        }

                        Image {
                            anchors.left: parent.left
                            anchors.leftMargin: 176
                            anchors.top: remind3_en_child.bottom
                            anchors.topMargin: 60
                            source: "../Assistantimages/barcode/pic3.png"
                        }
                    }

                    Item {
                        id:item4_en
                        width: 1199
                        height: 660

                        Image {
                            anchors.right: remind4_en.left
                            anchors.rightMargin: 35
                            anchors.top: parent.top
                            source: "../Assistantimages/title_bg.png"
                        }

                        Text {
                            id:remind4_en
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            text: "Fourth：Enable openning the device to run permissions";
                            //text: qsTr("四：开启设备允许运行权限");
                        }
                        Text {
                            id:remind4_en_child1
                            anchors.top: remind4_en.bottom
                            anchors.topMargin: 40
                            anchors.left: parent.left
                            anchors.leftMargin: 161
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "①please allow the software  to run c in";
                            //text: qsTr("①首次连接时<font color=\"#ff3057\">始终允许该软件运行权限</font>若如[帮助三]中所示，已开启USB调试，则此设置不显示");
                        }
                        Text {
                            id:remind4_en_child1_half
                            anchors.top: remind4_en_child1.bottom
                            anchors.topMargin: 6
                            anchors.left: parent.left
                            anchors.leftMargin: 161
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "the first place.If the USB debugging is";
                            //text: qsTr("①首次连接时<font color=\"#ff3057\">始终允许该软件运行权限</font>若如[帮助三]中所示，已开启USB调试，则此设置不显示");
                        }
                        Text {
                            id:remind4_en_child1_half2
                            anchors.top: remind4_en_child1_half.bottom
                            anchors.topMargin: 6
                            anchors.left: parent.left
                            anchors.leftMargin: 161
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "opened，the tooltip will not show up.";
                            //text: qsTr("①首次连接时<font color=\"#ff3057\">始终允许该软件运行权限</font>若如[帮助三]中所示，已开启USB调试，则此设置不显示");
                        }

                        Text {
                            id:remind4_en_child2
                            anchors.top: remind4_en_child1.top
                            x: 659
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "②Showing the asking of permission"
                            //text: qsTr("②对应显示此类权限信息，请<font color=\"#ff3057\">勾选并允许</font>，帮助你体验更优质服务");
                        }

                        Text {
                            id:remind4_en_child2_half
                            anchors.top: remind4_en_child1_half.top
                            x: 659
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "like this ，please allow it to help you"
                            //text: qsTr("②对应显示此类权限信息，请<font color=\"#ff3057\">勾选并允许</font>，帮助你体验更优质服务");
                        }

                        Text {
                            id:remind4_en_child2_half2
                            anchors.top: remind4_en_child1_half2.top
                            x: 659
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "get more Quality service."
                            //text: qsTr("②对应显示此类权限信息，请<font color=\"#ff3057\">勾选并允许</font>，帮助你体验更优质服务");
                        }

                        Image {
                            anchors.left: parent.left
                            anchors.leftMargin: 140
                            anchors.top: remind4_en_child1_half2.bottom
                            anchors.topMargin: 65
                            source: "../Assistantimages/barcode/pic10.png"
                        }

                        Image {
                            anchors.right: parent.right
                            anchors.rightMargin: 102
                            anchors.top: remind4_en_child1_half2.bottom
                            anchors.topMargin: 125
                            source: "../Assistantimages/barcode/pic9.png"
                        }

                    }

                    Item {
                        id:item5_en
                        width: 1199
                        height: 484

                        Image {
                            anchors.right: remind5_en.left
                            anchors.rightMargin: 35
                            anchors.top: parent.top
                            source: "../Assistantimages/title_bg.png"
                        }

                        Text {
                            id:remind5_en
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            width: 950
                            wrapMode: Text.WordWrap;
                            text: "Fifth：Allow the USB debugging (If the USB debugging is opened，";
                            //text: qsTr("五：允许USB调试（若如[帮助三]USB调试已开启，此时设置不显示）");
                        }
                        Text {
                            id:remind5_en_half
                            anchors.top: remind5_en.bottom
                            anchors.topMargin: 6
                            anchors.left: parent.left
                            anchors.leftMargin: 205
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "the pop-up box will not pop up).";
                            //text: qsTr("首次连接时勾选<font color=\"#ff3057\">始终允许该PC</font>并确定");
                        }
                        Text {
                            id:remind5_en_child
                            anchors.top: remind5_en_half.bottom
                            anchors.topMargin: 6
                            anchors.left: parent.left
                            anchors.leftMargin: 205
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "please allow  the PC the  to run permissions agility in the first place.";
                            //text: qsTr("首次连接时勾选<font color=\"#ff3057\">始终允许该PC</font>并确定");
                        }

                        Image {
                            anchors.left: parent.left
                            anchors.leftMargin: 158
                            anchors.top: remind5_en_child.bottom
                            anchors.topMargin: 54
                            source: "../Assistantimages/barcode/pic8.png"
                        }
                    }

                    Item {
                        id:item6_en
                        width: 1199
                        height: 450

                        Image {
                            anchors.right: remind6_en.left
                            anchors.rightMargin: 35
                            anchors.top: parent.top
                            source: "../Assistantimages/title_bg.png"
                        }

                        Text {
                            id:remind6_en
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.leftMargin: 113
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            width: 875;
                            wrapMode: Text.WordWrap
                            text: "Sixth：If  fails，please try to reconnect with data line，or just";
                            //text: qsTr("六：连接失败请尝试<font color=\"#ff3057\">重新</font>连接USB，或<font color=\"#ff3057\">重启</font>手机");
                        }
                        Text {
                            id:remind6_en_half
                            anchors.top: remind6_en.bottom
                            anchors.topMargin: 6
                            anchors.left: parent.left
                            anchors.leftMargin: 210
                            color: "#ffffff";
                            font.pixelSize: 30;
                            font.family: fontFamily;
                            text: "reboot your phone.";
                            //text: qsTr("①重新拔插USB，尝试重新连接");
                        }
                        Text {
                            id:remind6_en_child1
                            anchors.top: remind6_en_half.bottom
                            anchors.topMargin: 6
                            anchors.left: parent.left
                            anchors.leftMargin: 210
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "① Please pull out the data line and try to connect again.";
                            //text: qsTr("①重新拔插USB，尝试重新连接");
                        }
                        Text {
                            id:remind6_en_child2
                            anchors.top: remind6_en_child1.bottom
                            anchors.topMargin: 6
                            anchors.left: remind6_en_child1.left
                            color: "#ffffff";
                            font.pixelSize: 26;
                            font.family: fontFamily;
                            text: "②Reboot";
                            //text: qsTr("②重启手机");
                        }

                        Image {
                            anchors.left: parent.left
                            anchors.leftMargin: 178
                            anchors.top: remind6_en_child1.bottom
                            anchors.topMargin: 68
                            source: "../Assistantimages/barcode/pic6.png"
                        }

                        Image {
                            anchors.right: parent.right
                            anchors.rightMargin: 178
                            anchors.top: remind6_en_child2.bottom
                            anchors.topMargin: 68
                            source: "../Assistantimages/barcode/pic7.png"
                        }

                    }
                }

            }
        }
    }

    signal helpPageBackClicked();
}

