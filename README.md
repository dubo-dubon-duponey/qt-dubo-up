# DuboUp

> "Dubo Components" are lightweight, targeted c++ libraries meant for QT applications.
> They aim at providing *simple to use* interfaces for a range of functionality
(notification, crash reporting, zero conf, application update, torrent, etc).
> Fully scriptable, they are primarily meant for javascript (from a QWebEngine) - thought they are usable as well in plain QT.
> Put together, these components should provide a comprehensive foundation for these building a "WebRunner", similarly to Electron.

Ready-to-use, thin, QT wrapper around Sparkle and WinSparkle primarily meant to be used in Dubo products.
Will build Sparkle binary, and does bundle WinSparkle binary.

Some useful informations:
- http://el-tramo.be/blog/mixing-cocoa-and-qt/

Check the "demo" for some crude informations. You likely need to be familiar with appcast format and bundle/packaging.

Licensed under BSD2.

## NOTES

If you don't use the provided third-party libraries, you will have to handle runtime link issues yourself.
