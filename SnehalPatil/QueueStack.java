class MyQueue {

   
    Stack<Integer> queue = new Stack<>();
    Stack<Integer> stack = new Stack<>();
    /** Initialize your data structure here. */
    public MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
    	int popped;
    	if(stack.size() == 1) {
    		popped = stack.peek();
    		stack.pop();
    		
    	} else {
    		getQueue();
    		popped = queue.peek();
    		queue.pop();
    	}
        getStack();
        return popped;
    }
    
    /** Get the front element. */
    public int peek() {
        int peek;
        if(stack.size() == 1) {
            peek = stack.peek();
        } else {
            getQueue();
            peek = queue.peek();
        }
        getStack();
        return peek;
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        if(queue.isEmpty()) {
            return stack.size() == 0;
        } else {
            return queue.size() == 0;    
        }        
    }
    
    public void getQueue() {
        while(!stack.isEmpty()) {
                queue.push(stack.peek());
                stack.pop();
        }
    }
    
    public void getStack() {
        while(!queue.isEmpty()) {
                stack.push(queue.peek());
                queue.pop();
        }
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
