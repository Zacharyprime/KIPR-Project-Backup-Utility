#include <kipr/botball.h>

int main()
{
    printf("Mounting USB Drive... \n");
    system("mount /dev/sd?? /mnt");
    
    printf("Copying Files to USB Drive... \n");
    system("cp -r ~/Documents/KISS/* /mnt");
    
    printf("Removing unwanted files... \n");
    system("cd /mnt && rm *.json && rm -r bin && rm -r data && rm -r lib && rm -r src && rm -r include && rm tester.c"); 
    
    printf("Ejecting Flash Drive... \n");
    system("eject /dev/sd??");
    
    printf("DONE! \n");

    return 0;
}
