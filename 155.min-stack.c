/*
 * @lc app=leetcode.cn id=155 lang=c
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (46.89%)
 * Total Accepted:    15.3K
 * Total Submissions: 32.4K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 * 
 * 
 * 示例:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 */
typedef struct {
    int* data;
    int top;
    int bottom;
    int maxSize;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack * MyStack = (MinStack*)malloc(sizeof(MinStack*));
    MyStack->data = (int *)malloc(sizeof(int)*maxSize);
    MyStack->top = MyStack->bottom = 0;
    MyStack->maxSize = maxSize;
    return MyStack;
}

void minStackPush(MinStack* obj, int x) {
    int top = obj->top;
    if(top < obj->maxSize)
    {
        obj->data[top] = x;
        obj->top += 1;
    }
}

void minStackPop(MinStack* obj) {
    int top = obj->top;
    int bottom = obj->bottom;
    if (top >= bottom)
    {
        obj->data[top] = 0;
        obj->top -= 1;
    }
}

int minStackTop(MinStack* obj) {
    int top=obj->top;
    return obj->data[top];
}

int minStackGetMin(MinStack* obj) {
    
}

void minStackFree(MinStack* obj) {
    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
