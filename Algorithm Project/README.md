# Hill Climbing
Algorithm Project <br/>

ขอเกริ่นก่อนว่านำ Hill Climbing มาใช้หาคำตอบ (วิถีทางไปสู่คำตอบ) ของเกม 8-Puzzle โดยผู้ใช้งานเป็นผู้กำหนดสถานะเริ่มต้นของปัญหาของ และสถานะสิ้นสุดที่ต้องการ โดยจากการทดลองทำหลาย ๆ สถานะที่ต้องการหาคำตอบ พบว่าบางปัญหาก็ไม่สามารถหาวิถีทางไปสู่คำตอบได้ จึงไม่การันตีว่า Hill Climbing จะสามารถแก้ปัญหา 8-Puzzle ได้ทุกรูปแบบที่ต้องการ (อาจคิดได้ว่า Hill Climbing ไม่เหมาะที่จะนำมาใช้แก้ปัญหา 8-Puzzle สักเท่าไหร่) 

--------------------------------------------------------------

**คำถาม**

เมื่อปีนเขาไปติดอยู่ที่ local optimum ไปไม่ถึง global optimum ต้องใช้วิธีอะไรแก้ ?
- ใช้วิธีการ Simulated Annealing (การจำลองการอบเหนียว) 
- ใช้แนวคิดที่รับ heuristic ที่แย่บ้างเพื่อให้หลุดออกจาก local optimum

**คำอธิบาย**
- กำหนดสถานะเริ่มต้นของปัญหาและสถานะสุดท้ายที่ต้องการในไฟล์ input.txt
- ส่วนของการแสดงผลจะอยู่ในโฟลเดอร์ print, display.txt คือ state ที่ถูกสร้างและถูกเลือกในแต่ละรอบ, cost.txt คือค่าตัดสินใจของ state ที่ดีที่สุดที่ถูกเลือกในแต่ละรอบ

--------------------------------------------------------------

**อ้างอิง** <br/>
- [Hill climbing - Wikipedia](https://en.wikipedia.org/wiki/Hill_climbing) <br/>
- [Prof.Dr. Boonserm Kijsirikul - Artificial Intelligence (p. 36 - 42)](https://www.cp.eng.chula.ac.th/~boonserm/teaching/ai1.0.2.pdf)      <br/>
- [Simulated annealing - Wikipedia](https://en.wikipedia.org/wiki/Simulated_annealing)      <br/>
- [การจำลองการอบเหนียว](https://th.wikipedia.org/wiki/การจำลองการอบเหนียว)      <br/>

--------------------------------------------------------------
  
  
