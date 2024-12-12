/* 2558. Take Gifts From the Richest Pile 

You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
Return the number of gifts remaining after k seconds. */

long long pickGifts(vector<int>& gifts, int k) {
    std::priority_queue<long long> maxHeap;
    for (int gift : gifts) {
        maxHeap.push(gift);
    }
    for (int i = 0; i < k; ++i) {
        if (maxHeap.empty()) break;
        long long current = maxHeap.top();
        long long leftover = static_cast<long long>(sqrt(current));

        maxHeap.pop();
        maxHeap.push(leftover);
    }
    long long sum = 0;
    while (!maxHeap.empty()) {
        sum += maxHeap.top();
        maxHeap.pop();
    }
    
    return sum;
}
