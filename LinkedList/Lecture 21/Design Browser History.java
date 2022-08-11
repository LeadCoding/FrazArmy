class BrowserHistory {
    int current;
    ArrayList<String> history;
    public BrowserHistory(String homepage) {    
        this.history = new ArrayList<>();
        history.add(homepage);
		this.current = 0;
    }
    
    public void visit(String url) {

        //delete forward history

        while (history.size()-1 > current) {
            //which means delete everything beyond our current website
            history.remove(history.size()-1);
        }
        history.add(url);
        ++current;
    }
    
    public String back(int steps) {

        //if we can't get enough back, we return first thing in our history

        if (steps>current) current = 0;

        //if there will be no arrayindexoutofrange error, go back

        else current -= steps;

        //return current webpage

        return history.get(current);
    }
    
    public String forward(int steps) {

        //if we are going to move more than our arraylist then we will return the last element

        if (steps+current>=history.size()) current = history.size() - 1;

        //if there will be no arrayindexoutofrange error, go forward!

        else current += steps;
        
        return history.get(current);
        
        //return the current webpage
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */