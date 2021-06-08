--- chrome/browser/media/webrtc/webrtc_log_uploader.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/media/webrtc/webrtc_log_uploader.cc
@@ -357,6 +357,8 @@ void WebRtcLogUploader::SetupMultipart(
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
 #else
 #error Platform not supported.
 #endif
