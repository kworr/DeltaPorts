--- chrome/browser/flag_descriptions.h.orig	2021-01-18 21:28:50 UTC
+++ chrome/browser/flag_descriptions.h
@@ -19,9 +19,9 @@
 #include "ppapi/buildflags/buildflags.h"
 #include "printing/buildflags/buildflags.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // This file declares strings used in chrome://flags. These messages are not
 // translated, because instead of end-users they target Chromium developers and
@@ -2699,7 +2699,7 @@ extern const char kEnableNewBadgeOnMenuItemsDescriptio
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 
 extern const char kEnableMediaFeedsName[];
@@ -2726,7 +2726,7 @@ extern const char kRemoteCopyProgressNotificationDescr
 extern const char kDirectManipulationStylusName[];
 extern const char kDirectManipulationStylusDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_CHROMEOS)
@@ -2736,12 +2736,12 @@ extern const char kWebContentsOcclusionDescription[];
 
 #endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_CHROMEOS)
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 #if BUILDFLAG(USE_TCMALLOC)
 extern const char kDynamicTcmallocName[];
 extern const char kDynamicTcmallocDescription[];
 #endif  // BUILDFLAG(USE_TCMALLOC)
-#endif  // #if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#endif  // #if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if !defined(OS_ANDROID) && !defined(OS_CHROMEOS)
 extern const char kUserDataSnapshotName[];
@@ -2753,11 +2753,11 @@ extern const char kWebShareName[];
 extern const char kWebShareDescription[];
 #endif  // defined(OS_WIN) || defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD) || \
     defined(OS_MAC)
 extern const char kEnableEphemeralGuestProfilesOnDesktopName[];
 extern const char kEnableEphemeralGuestProfilesOnDesktopDescription[];
-#endif  // defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS) ||
+#endif  // defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD) ||
         // defined(OS_MAC)
 
 // Feature flags --------------------------------------------------------------
