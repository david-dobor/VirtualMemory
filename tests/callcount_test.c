unsigned long i = 0;
unsigned long j = 0;
int main() {
    // ensures that syscall 361 is incrementing
    syscall(361, &i);	
    j = i;
    syscall(361, &i);	
    if (i == j + 1) {
        return 0;
    }
    return 1;
}
