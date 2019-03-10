char* reverseOnlyLetters(char* S) {
    int start = 0;
    int end = strlen(S)-1;
    while(start < end)
    {
        if((S[start] < 'A' || S[start] > 'Z') && (S[start] < 'a' || S[start] > 'z'))
        {
            start++;
            continue;
        }
        if((S[end] < 'A' || S[end] > 'Z') && (S[end] < 'a' || S[end] > 'z'))
        {
            end--;
            continue;
        }
        
            char tmp = S[start];
        S[start] = S[end];
        S[end] = tmp;
        start++;
        end--;
        
        
    }
    return S;
}