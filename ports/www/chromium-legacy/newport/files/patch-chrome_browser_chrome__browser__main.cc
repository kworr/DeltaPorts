--- chrome/browser/chrome_browser_main.cc.orig	2021-01-18 21:28:49 UTC
+++ chrome/browser/chrome_browser_main.cc
@@ -247,7 +247,7 @@
 #endif  // defined(OS_WIN)
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/browser/metrics/desktop_session_duration/desktop_session_duration_tracker.h"
 #include "chrome/browser/metrics/desktop_session_duration/touch_mode_stats_tracker.h"
 #include "chrome/browser/profiles/profile_activity_metrics_recorder.h"
@@ -926,7 +926,7 @@ int ChromeBrowserMainParts::PreCreateThreadsImpl() {
       AddFirstRunNewTabs(browser_creator_.get(), master_prefs_->new_tabs);
     }
 
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // Create directory for user-level Native Messaging manifest files. This
     // makes it less likely that the directory will be created by third-party
     // software with incorrect owner or permission. See crbug.com/725513 .
@@ -935,7 +935,7 @@ int ChromeBrowserMainParts::PreCreateThreadsImpl() {
                                  &user_native_messaging_dir));
     if (!base::PathExists(user_native_messaging_dir))
       base::CreateDirectory(user_native_messaging_dir);
-#endif  // defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   }
 #endif  // !defined(OS_ANDROID) && !defined(OS_CHROMEOS)
 
@@ -957,7 +957,7 @@ int ChromeBrowserMainParts::PreCreateThreadsImpl() {
 #endif  // defined(OS_MAC)
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   metrics::DesktopSessionDurationTracker::Initialize();
   ProfileActivityMetricsRecorder::Initialize();
   TouchModeStatsTracker::Initialize(
@@ -1114,6 +1114,7 @@ void ChromeBrowserMainParts::PostBrowserStart() {
       base::TimeDelta::FromMinutes(1));
 
 #if !defined(OS_ANDROID)
+#if !defined(OS_BSD)
   if (base::FeatureList::IsEnabled(features::kWebUsb)) {
     web_usb_detector_.reset(new WebUsbDetector());
     content::GetUIThreadTaskRunner({base::TaskPriority::BEST_EFFORT})
@@ -1121,6 +1122,7 @@ void ChromeBrowserMainParts::PostBrowserStart() {
                    base::BindOnce(&WebUsbDetector::Initialize,
                                   base::Unretained(web_usb_detector_.get())));
   }
+#endif
   if (base::FeatureList::IsEnabled(features::kTabMetricsLogging)) {
     // Initialize the TabActivityWatcher to begin logging tab activity events.
     resource_coordinator::TabActivityWatcher::GetInstance();
