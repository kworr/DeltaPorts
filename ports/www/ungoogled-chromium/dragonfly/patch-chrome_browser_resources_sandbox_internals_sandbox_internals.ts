diff --git chrome/browser/resources/sandbox_internals/sandbox_internals.ts chrome/browser/resources/sandbox_internals/sandbox_internals.ts
index f6d2f3f0bc41..1782f48d6dcb 100644
--- chrome/browser/resources/sandbox_internals/sandbox_internals.ts
+++ chrome/browser/resources/sandbox_internals/sandbox_internals.ts
@@ -2,7 +2,7 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
-// <if expr="is_linux or is_chromeos">
+// <if expr="is_posix or is_chromeos">
 import './strings.m.js';
 
 import {loadTimeData} from 'chrome://resources/js/load_time_data.js';
@@ -121,7 +121,7 @@ function androidHandler() {
 }
 // </if>
 
-// <if expr="is_linux or is_chromeos">
+// <if expr="is_posix or is_chromeos">
 
 /**
  * Adds a status row that reports either Yes or No.
@@ -182,7 +182,7 @@ document.addEventListener('DOMContentLoaded', () => {
   // <if expr="is_android">
   androidHandler();
   // </if>
-  // <if expr="is_linux or is_chromeos">
+  // <if expr="is_posix or is_chromeos">
   linuxHandler();
   // </if>
 });
