--- chrome/browser/media/webrtc/webrtc_logging_controller.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/media/webrtc/webrtc_logging_controller.cc
@@ -23,10 +23,10 @@
 #include "content/public/browser/browser_context.h"
 #include "content/public/browser/render_process_host.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "content/public/browser/child_process_security_policy.h"
 #include "storage/browser/file_system/isolated_context.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 using webrtc_event_logging::WebRtcEventLogManager;
 
@@ -272,7 +272,7 @@ void WebRtcLoggingController::StartEventLogging(
       web_app_id, callback);
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void WebRtcLoggingController::GetLogsDirectory(
     LogsDirectoryCallback callback,
     LogsDirectoryErrorCallback error_callback) {
@@ -318,7 +318,7 @@ void WebRtcLoggingController::GrantLogsDirectoryAccess
       FROM_HERE,
       base::BindOnce(std::move(callback), file_system.id(), registered_name));
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 void WebRtcLoggingController::OnRtpPacket(
     std::unique_ptr<uint8_t[]> packet_header,
