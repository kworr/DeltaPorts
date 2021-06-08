--- extensions/shell/browser/api/runtime/shell_runtime_api_delegate.cc.orig	2021-01-18 21:28:59 UTC
+++ extensions/shell/browser/api/runtime/shell_runtime_api_delegate.cc
@@ -46,7 +46,7 @@ void ShellRuntimeAPIDelegate::OpenURL(const GURL& unin
 bool ShellRuntimeAPIDelegate::GetPlatformInfo(PlatformInfo* info) {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   info->os = api::runtime::PLATFORM_OS_CROS;
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   info->os = api::runtime::PLATFORM_OS_LINUX;
 #endif
   return true;
