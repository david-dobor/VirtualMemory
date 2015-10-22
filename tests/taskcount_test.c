unsigned long i = 0;
int main() {
    syscall(360, &i);	
    if (i > 0) {
        return 0;
    }
    return 1;
}
