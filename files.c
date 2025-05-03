
#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "r+");  // Open for read and write
    int res;
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    res = fseek(file,0 , SEEK_END);
    printf("Fseek returned %d\n",res);

    fputs("New LastLine \n",file);
    fflush(file);
    fseek(file,0, SEEK_SET);
    printf("Location is %ld\n",ftell(file));


    // Reading from file
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        // Print each line to the standard output.
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);
    return 0;
}
