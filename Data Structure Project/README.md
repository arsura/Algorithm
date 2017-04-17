# Trie
  Data Structure Project
  
  ฟังก์ชั่นพื้นฐาน
  - Space O(nm)
  - Insert O(m), เพิ่มข้อมูล
  - Delete O(m), ลบข้อมูล
  - Modify (Replace) O(m), การแก้ไขคำโดยสามารถเรียกใช้ฟังก์ชั่น Delete และ Insert เพื่อ Replace
  - Destroy O(mn), ลบโหนดทุกโหนดใน Trie
  - SearchAllWord, O(mn) เรียกดูคำทุกคำใน Trie  
  
  ฟังก์ชั่นเพิ่มเติม
  - Autocomplete O(mk)
  - StringMatching O(mn)
  
  โดย m คือความยาวตัวอักษร, n คือจำนวนตัวอักษรทั้งหมด, k คือจำนวนตัวอักษรที่ค้นเจอ (ซึ่งไม่ใช่ทุกคำใน Trie)
  
  --------------------------------------------------------------
  คำถาม
  
  ถ้าต้องการค้นหาคำแบบ reverse (ค้นจากท้ายคำ) ตัวอย่างเช่นมีคำว่า vat, fat, rat, cat, hat อยู่ใน trie ต้องการค้น at แล้วได้คำที่ว่าทั้งหมดออกมาจะต้องทำอย่างไร ? 
  - สร้าง Trie (Reverse Trie) สำหรับเก็บ reverse word (คำที่สลับจากหลังมาหน้า) ควบคู่ไปกับ Trie ปกติด้วย, จะมี 2 Root Node ซึ่งอิสระต่อกันในการค้นหาและการทำ     Autocomplete แต่สำหรับขั้นตอนการ Delete, Modify, Destroy, Insert ต้องเรียกทั้ง Trie และ Reverse Trie เพื่อดำเนินการ
  - ทำการเพิ่มการจองพื้นที่ของตัวชี้คีย์ในจาก 128 เป็น 256 โดยตำแหน่งที่ 129 - 255 จะทำการเก็บ reverse word จะมี Root Node เพียง 1 เดียว
  
  แต่ทั้งนี้ไม่ว่าจะวิธีไหนก็จะใช้พื้นที่เพิ่มเป็น 2 เท่า
  --------------------------------------------------------------
  แหล่งอ้างอิง
  - [ทรัย (โครงสร้างข้อมูล)]      
  (https://th.wikipedia.org/wiki/%E0%B8%97%E0%B8%A3%E0%B8%B1%E0%B8%A2_(%E0%B9%82%E0%B8%84%E0%B8%A3%E0%B8%87%E0%B8%AA%E0%B8%A3%E0%B9%89%E0%    B8%B2%E0%B8%87%E0%B8%82%E0%B9%89%E0%B8%AD%E0%B8%A1%E0%B8%B9%E0%B8%A5)) <br/>
  - [Create GitHub Directory Download Link by DownGit](https://minhaskamal.github.io/DownGit/#/home) <br/>
  
