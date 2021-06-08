--- components/feature_engagement/public/event_constants.h.orig	2021-01-18 21:28:55 UTC
+++ components/feature_engagement/public/event_constants.h
@@ -12,16 +12,16 @@ namespace feature_engagement {
 namespace events {
 
 // Desktop and IOS.
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 // The user has explicitly opened a new tab via an entry point from inside of
 // Chrome.
 extern const char kNewTabOpened[];
 #endif  // defined(OS_WIN) || defined(OS_APPLE) ||
-        // defined(OS_LINUX) || defined(OS_CHROMEOS)
+        // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // Desktop
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 // A new tab was opened when 5 (or more) tabs were already open.
 extern const char kSixthTabOpened[];
@@ -57,7 +57,7 @@ extern const char kWebUITabStripOpened[];
 // The PWA was installed by the user.
 extern const char kDesktopPwaInstalled[];
 
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if defined(OS_IOS)
