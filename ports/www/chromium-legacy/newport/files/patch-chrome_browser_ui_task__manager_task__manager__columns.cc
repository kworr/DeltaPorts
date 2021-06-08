--- chrome/browser/ui/task_manager/task_manager_columns.cc.orig	2020-11-13 06:36:38 UTC
+++ chrome/browser/ui/task_manager/task_manager_columns.cc
@@ -93,10 +93,10 @@ const TableColumnData kColumns[] = {
      base::size("100000") * kCharWidth, -1, true, false, false},
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
     {IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN, ui::TableColumn::RIGHT, -1, 0,
      base::size("999") * kCharWidth, -1, true, false, false},
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
     {IDS_TASK_MANAGER_PROCESS_PRIORITY_COLUMN, ui::TableColumn::LEFT, -1, 0,
      base::size("background") * kCharWidth, -1, true, true, false},
     {IDS_TASK_MANAGER_KEEPALIVE_COUNT_COLUMN, ui::TableColumn::RIGHT, -1, 0,
