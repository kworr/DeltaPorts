--- src/3rdparty/chromium/third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc.orig	Mon Jun 10 11:34:19 2024
+++ src/3rdparty/chromium/third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc	Fri Feb
@@ -19,7 +19,7 @@
 #endif
 
 #if defined(HAS_STRPTIME) && HAS_STRPTIME
-#if !defined(_XOPEN_SOURCE) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(_XOPEN_SOURCE) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
 #define _XOPEN_SOURCE 500  // Exposes definitions for SUSv2 (UNIX 98).
 #endif
 #endif
