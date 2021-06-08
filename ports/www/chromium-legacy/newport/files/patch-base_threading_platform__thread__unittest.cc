--- base/threading/platform_thread_unittest.cc.orig	2021-01-18 21:28:45 UTC
+++ base/threading/platform_thread_unittest.cc
@@ -312,7 +312,7 @@ TEST(PlatformThreadTest,
 // and hardcodes what we know. Please inform scheduler-dev@chromium.org if this
 // proprerty changes for a given platform.
 TEST(PlatformThreadTest, CanIncreaseThreadPriority) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // On Ubuntu, RLIMIT_NICE and RLIMIT_RTPRIO are 0 by default, so we won't be
   // able to increase priority to any level.
   constexpr bool kCanIncreasePriority = false;
@@ -406,9 +406,9 @@ TEST(PlatformThreadTest, SetHugeThreadName) {
 
 TEST(PlatformThreadTest, GetDefaultThreadStackSize) {
   size_t stack_size = PlatformThread::GetDefaultThreadStackSize();
-#if defined(OS_WIN) || defined(OS_IOS) || defined(OS_FUCHSIA) || \
-    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) &&              \
-     !defined(THREAD_SANITIZER)) ||                              \
+#if defined(OS_WIN) || defined(OS_IOS) || defined(OS_FUCHSIA) ||       \
+    ((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && \
+     !defined(THREAD_SANITIZER)) ||                                    \
     (defined(OS_ANDROID) && !defined(ADDRESS_SANITIZER))
   EXPECT_EQ(0u, stack_size);
 #else
