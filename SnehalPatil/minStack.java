class MinStack {

    Stack<Integer> min = new Stack<Integer>();
    Stack<Integer> stack = new Stack<Integer>();
    
    public void push(int x) {
        stack.push(x);
    	if(min.isEmpty() || min.peek() > x) {
    		min.push(x);
    	} else {
            min.push(min.peek());
        }
    }
    
    public int getMin() {
		return min.peek();
    }
   
    public void pop() {
        stack.pop();
        min.pop();
    }
    
    public int top() {
        return stack.peek();
    }
}
