android-no-sdk {
    target.path = /data/user/qt
    export(target.path)
    INSTALLS += target
} else:android {
    x86 {
        target.path = /libs/x86
    } else: armeabi-v7a {
        target.path = /libs/armeabi-v7a
    } else {
        target.path = /libs/armeabi
    }
    export(target.path)
    INSTALLS += target
} else:unix {
    isEmpty(target.path) {
        qnx {
            target.path = /tmp/$${TARGET}/bin
        } else {
        INCLUDEPATH +=  /opt/atp/2014.05+snapshot/sysroots/cortexa9hf-vfp-neon-mel-linux-gnueabi/usr/include \
                        /opt/atp/2014.05+snapshot/sysroots/cortexa9hf-vfp-neon-mel-linux-gnueabi/usr/include/CommonAPI-2.1 \
                        /opt/atp/2014.05+snapshot/sysroots/cortexa9hf-vfp-neon-mel-linux-gnueabi/usr/include/dbus-1.0 \
                        /opt/atp/2014.05+snapshot/sysroots/cortexa9hf-vfp-neon-mel-linux-gnueabi/usr/include/libxml2 \
                        /opt/atp/2014.05+snapshot/sysroots/cortexa9hf-vfp-neon-mel-linux-gnueabi/usr/include/gio-unix-2.0 \
                        /opt/atp/2014.05+snapshot/sysroots/cortexa9hf-vfp-neon-mel-linux-gnueabi/usr/include/gstreamer-0.10 \
                        /opt/atp/2014.05+snapshot/sysroots/cortexa9hf-vfp-neon-mel-linux-gnueabi/usr/include/glib-2.0 \
                        /opt/atp/2014.05+snapshot/sysroots/cortexa9hf-vfp-neon-mel-linux-gnueabi/usr/lib/dbus-1.0/include \
                        /opt/atp/2014.05+snapshot/sysroots/cortexa9hf-vfp-neon-mel-linux-gnueabi/usr/lib/glib-2.0/include \

        LIBS += -L/opt/atp/2014.05+snapshot/sysroots/cortexa9hf-vfp-neon-mel-linux-gnueabi/lib \
                -lz -lssl -lcrypto -lpng16 -licui18n -licuuc -llttng-ust-tracepoint -lurcu-cds -lurcu-common -lgc_wayland_protocol -lwayland-server -licudata -lwayland-client -lffi

        LIBS += -L/opt/atp/2014.05+snapshot/sysroots/cortexa9hf-vfp-neon-mel-linux-gnueabi/usr/lib \

#        LIBS += -lgstcli

        CONFIG += c++11
        QMAKE_CXXFLAGS += -O2 -g -Wall -c -fmessage-length=0 -std=c++0x -pthread -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 -mno-unaligned-access -std=c++0x -fcommon -mfpu=vfp
        QMAKE_CFLAGS += -O2 -g -Wall -c -fmessage-length=0 -pthread -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 -mno-unaligned-access -fcommon -mfpu=vfp
        DESTDIR = $$DESTDIR_ARM
            target.path = /opt/$${TARGET}/bin
        }
        export(target.path)
    }
    INSTALLS += target
}

export(INSTALLS)
