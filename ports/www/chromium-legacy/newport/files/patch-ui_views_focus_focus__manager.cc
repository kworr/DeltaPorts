--- ui/views/focus/focus_manager.cc.orig	2021-01-18 21:29:49 UTC
+++ ui/views/focus/focus_manager.cc
@@ -621,7 +621,7 @@ bool FocusManager::RedirectAcceleratorToBubbleAnchorWi
   if (!focus_manager->IsAcceleratorRegistered(accelerator))
     return false;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Processing an accelerator can delete things. Because we
   // need these objects afterwards on Linux, save widget_ as weak pointer and
   // save the close_on_deactivate property value of widget_delegate in a
@@ -636,7 +636,7 @@ bool FocusManager::RedirectAcceleratorToBubbleAnchorWi
   const bool accelerator_processed =
       focus_manager->ProcessAccelerator(accelerator);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Need to manually close the bubble widget on Linux. On Linux when the
   // bubble is shown, the main widget remains active. Because of that when
   // focus is set to the main widget to process accelerator, the main widget
