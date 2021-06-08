--- chrome/browser/metrics/process_memory_metrics_emitter.cc.orig	2021-01-18 21:28:50 UTC
+++ chrome/browser/metrics/process_memory_metrics_emitter.cc
@@ -497,7 +497,7 @@ void EmitProcessUmaAndUkm(const GlobalMemoryDump::Proc
 
   builder->SetPrivateMemoryFootprint(pmd.os_dump().private_footprint_kb / kKiB);
   builder->SetSharedMemoryFootprint(pmd.os_dump().shared_footprint_kb / kKiB);
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   builder->SetPrivateSwapFootprint(pmd.os_dump().private_footprint_swap_kb /
                                    kKiB);
 #endif
@@ -520,7 +520,7 @@ void EmitProcessUmaAndUkm(const GlobalMemoryDump::Proc
   MEMORY_METRICS_HISTOGRAM_MB(std::string(kMemoryHistogramPrefix) +
                                   process_name + ".SharedMemoryFootprint",
                               pmd.os_dump().shared_footprint_kb / kKiB);
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   MEMORY_METRICS_HISTOGRAM_MB(std::string(kMemoryHistogramPrefix) +
                                   process_name + ".PrivateSwapFootprint",
                               pmd.os_dump().private_footprint_swap_kb / kKiB);
