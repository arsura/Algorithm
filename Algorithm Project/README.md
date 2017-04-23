# Hill Climbing
Algorithm Project <br/>

ขอเกริ่นก่อนว่านำ Hill Climbing มาใช้หาคำตอบ (วิถีทางไปสู่คำตอบ) ของเกม 8-Puzzle โดยผู้ใช้งานเป็นผู้กำหนดสถานะเริ่มต้นของปัญหาของ และสถานะสิ้นสุดที่ต้องการ โดยจากการทดลองทำหลาย ๆ สถานะที่ต้องการหาคำตอบ พบว่าบางปัญหาก็ไม่สามารถหาวิถีทางไปสู่คำตอบได้ จึงไม่การันตีว่า Hill Climbing จะสามารถแก้ปัญหา 8-Puzzle ได้ทุกรูปแบบที่ต้องการ (อาจเพราะ Hill Climbing ไม่เหมาะที่จะนำมาใช้แก้ปัญหา 8-Puzzle สักเท่าไหร่) 

--------------------------------------------------------------

**Manhattan Heuristic** <br/>
เป็นค่าตัดสินใจที่ใช้เลือกเส้นทางถัดไปที่ดีที่สุดในการแก้ปัญหา 8-Puzzle โดยเทียบสถานะที่สร้างใหม่ กับสถานะสิ้นสุด ถ้าสถานะที่สร้างใหม่อันไหนน้อยที่สุดก็ให้เลือกสถานะเป็นสถานะปัจจุบัน โดยจะแสดงตัวอย่างการคิดหา Manhattan Distance ด้านล่าง<br/>

    สถานะที่สร้างใหม่คือ
    4 7 8
    5 6 3
    1 2 0
    
    และมีสถานะเป้าหมายคือ
    1 4 8
    3 6 5
    2 7 0
    
    จะเห็นว่าไม่ตรงกันทั้งหมด 6 ตัว, 0 แทนช่องว่าง
    ตำแหน่งที่ 1: 4 แทนค่า Manhattan = abs(x1 - x2) + abs(y1 - y2) = 1 + 0 = 1
    ตำแหน่งที่ 2: 7 แทนค่า Manhattan = abs(x1 - x2) + abs(y1 - y2) = 0 + 2 = 2
    ตำแหน่งที่ 3: 5 แทนค่า Manhattan = abs(x1 - x2) + abs(y1 - y2) = 2 + 0 = 2
    ตำแหน่งที่ 4: 3 แทนค่า Manhattan = abs(x1 - x2) + abs(y1 - y2) = 2 + 0 = 2
    ตำแหน่งที่ 5: 1 แทนค่า Manhattan = abs(x1 - x2) + abs(y1 - y2) = 0 + 2 = 2
    ตำแหน่งที่ 6: 2 แทนค่า Manhattan = abs(x1 - x2) + abs(y1 - y2) = 1 + 0 = 1
    ดังนั้นค่า Manhattan Heuristic เท่ากับ 1 + 2 + 2 + 2 + 2 + 1 = 10
    
    สรุปง่าย ๆ คือในตำแหน่งใดตำแหน่งหนึ่งของสถานะที่สร้างใหม่ถ้าตัวเลขนั้นไม่ได้ตรงกับสถานะเป้าหมาย 
    ให้ทำการหาว่าต้องเดินกี่ก้าวให้น้อยที่สุดจึงจะอยู่ตำแหน่งเดียวกันกับสถานะเป้าหมาย แล้วหาผลรวมของทั้งหมด
    

--------------------------------------------------------------

**ขั้นตอนการทำงานของ Hill Climbing กับปัญหา 8-Puzzle**

<img src="https://github.com/arsura/Algorithm/blob/master/Algorithm%20Project/Hill_Climbing_8Puzzle/picture/procedures.png" alt="alt text" width="900" height="1433">

จากภาพจะเห็นได้ว่าการเลือกสถานะถัดไปในแต่ละครั้งต้องมีการยอมรับค่าที่แย่กว่าสถานะปัจุบันด้วย (แต่เป็นสถานะที่ดีที่สุดเมื่อเทียบกับ Neighbor Node) เพื่อไม่ให้ติด Local Optimum จะทำให้ไปต่อไม่ได้

--------------------------------------------------------------

**คำถาม**

เมื่อปีนเขาไปติดอยู่ที่ local optimum ไปไม่ถึง global optimum ต้องใช้วิธีอะไรแก้ ?
<img src="https://github.com/arsura/Algorithm/blob/master/Algorithm%20Project/Hill_Climbing_8Puzzle/picture/local_opt.png" alt="alt text" width="450" height="450">

- ใช้วิธีการที่รับ heuristic ที่แย่บ้างเพื่อให้หลุดออกจาก local optimum
<img src="https://github.com/arsura/Algorithm/blob/master/Algorithm%20Project/Hill_Climbing_8Puzzle/picture/hill_climbing_graph.png" alt="alt text" width="" height="">

- ใช้วิธีการ Simulated Annealing (การจำลองการอบเหนียว)
<img src="https://github.com/arsura/Algorithm/blob/master/Algorithm%20Project/Hill_Climbing_8Puzzle/picture/simulated_annealing_graph.png" alt="alt text" width="" height="">
จากกราฟจะเห็นได้ว่ามีการยอมรับค่าตัดสินใจในช่วงที่กว้างมาก และมีการรับค่าตัดสินใจที่แย่ ๆ เกิดขึ้น จึงมั่นใจได้ว่าจะสามารถหลุดออกจาก Local Optimum แน่นอน


 **กราฟที่นำมาแสดงใช้สถานะเริ่มต้นและสถานะสิ้นสุดเดียวกันกับสถานะที่แสดงในหัวข้อขั้นตอนการทำงาน**
--------------------------------------------------------------

**คำอธิบาย**
- กำหนดสถานะเริ่มต้นของปัญหาและสถานะสุดท้ายที่ต้องการในไฟล์ input.txt
- ส่วนของการแสดงผลจะอยู่ในโฟลเดอร์ print
- display.txt คือ state ที่ถูกสร้างและถูกเลือกในแต่ละรอบ
- cost.txt คือค่าตัดสินใจของ state ที่ดีที่สุดที่ถูกเลือกในแต่ละรอบ

--------------------------------------------------------------

**อ้างอิง** <br/>
- [Hill climbing - Wikipedia](https://en.wikipedia.org/wiki/Hill_climbing) <br/>
- [Prof.Dr. Boonserm Kijsirikul - Artificial Intelligence (p. 36 - 42)](https://www.cp.eng.chula.ac.th/~boonserm/teaching/ai1.0.2.pdf)      <br/>
- [Simulated annealing - Wikipedia](https://en.wikipedia.org/wiki/Simulated_annealing)      <br/>
- [การจำลองการอบเหนียว](https://th.wikipedia.org/wiki/การจำลองการอบเหนียว)      <br/>

--------------------------------------------------------------
  
  
