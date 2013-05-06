APP_NAME = KeePassForBlackBerry

CONFIG += qt warn_on cascades10
LIBS   += -lbbdata
LIBS   += -lbbsystem
LIBS   += -lbbplatform
LIBS   += -lbbcascadespickers
LIBS   += -lbb

include(config.pri)

device {
    CONFIG(debug, debug|release) {
        # Device-Debug custom configuration
    }

    CONFIG(release, debug|release) {
        # Device-Release custom configuration
    }
}

simulator {
    CONFIG(debug, debug|release) {
        # Simulator-Debug custom configuration
    }
}
