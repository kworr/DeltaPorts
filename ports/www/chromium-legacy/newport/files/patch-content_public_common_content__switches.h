--- content/public/common/content_switches.h.orig	2021-01-18 21:28:57 UTC
+++ content/public/common/content_switches.h
@@ -245,7 +245,7 @@ CONTENT_EXPORT extern const char kWebXrRuntimeOrientat
 CONTENT_EXPORT extern const char kWebXrRuntimeOpenXr[];
 CONTENT_EXPORT extern const char kWebXrRuntimeWMR[];
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ANDROID)) || defined(OS_BSD)
 CONTENT_EXPORT extern const char kEnableAcceleratedVideoDecode[];
 #endif
 CONTENT_EXPORT extern const char kDisableAcceleratedVideoDecode[];
@@ -266,7 +266,7 @@ CONTENT_EXPORT extern const char kRemoteDebuggingSocke
 CONTENT_EXPORT extern const char kRendererWaitForJavaDebugger[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
