--- chrome/browser/defaults.cc.orig	2020-11-13 06:36:36 UTC
+++ chrome/browser/defaults.cc
@@ -43,7 +43,7 @@ const bool kSyncAutoStarts = true;
 const bool kSyncAutoStarts = false;
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 const bool kScrollEventChangesTab = true;
 #else
 const bool kScrollEventChangesTab = false;
