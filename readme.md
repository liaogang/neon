## neon指令的等价cpp实现

[NEON](https://zh.wikipedia.org/wiki/ARM%E6%9E%B6%E6%A7%8B#%E9%80%B2%E9%9A%8ESIMD%EF%BC%88NEON%EF%BC%89)是arm架构里具有一組廣泛的指令集、各自的暫存器檔案，以及獨立執行的硬體。常用于加速图形，游戏，语音等运算。



### 动机

在研究一个信息摘要算法时，发现其中使用了neon算法

虽然不是很难，查指令手册,在lldb一个个测试对比,  但也花了一些精力.

### 参考

http://infocenter.arm.com/help/topic/com.arm.doc.dui0204ic/DUI0204IC_rvct_assembler_guide.pdf

https://static.docs.arm.com/dui0802/a/DUI0802A_armasm_reference_guide.pdf

http://infocenter.arm.com/help/topic/com.arm.doc.ihi0073a/IHI0073A_arm_neon_intrinsics_ref.pdf