/*
KIPR Project Backup Utility
by: Zachary Sasser
*/    
#include <kipr/botball.h>

int backup()
{
    printf("Mounting USB Drive... \n");
    system("sudo mount /dev/sd?? /mnt");
    
    printf("Copying Files to USB Drive... \n");
    system("cp -r /home/root/Documents/KISS/* /mnt");
    
    printf("Removing unwanted files... \n");
    system("cd /mnt && rm *.json && rm -r bin && rm -r data && rm -r lib && rm -r src && rm -r include"); 
    
    system("sudo umount /dev/sd??");
    
    console_clear();
    printf("\n \nAll projects backed up on flash drive! \n");

    return 1;
}

int restore(){
	printf("Mounting USB drive... \n");
	system("sudo mount /dev/sd?? /mnt");
	
	printf("Moving projects from flash drive to the Controller... \n");
	system("cp -r /mnt/* /home/root/Documents/KISS");
	
    system("sudo umount /dev/sd??");
    
    console_clear();
	printf("\n \nAll programs restored with USB flash drive \n \n");
    
	return 1;
}

int clearDrive(){
    printf("Clearing flash drive... \n");  
    system("sudo umount /dev/sd??");
    system("sudo mkfs.vfat -F 32 /dev/sd??");
    
    printf("\nFlash drive is now cleared. \n \n");
    return 1;
}

int main(){
    system("sudo umount /dev/sd??");
	printf("Welcome to the KIPR Project Backup Utility! \n \n");
	printf("Press A to move your projects to a flash drive. \n");
	printf("Press B to use the backup stored on your flash drive! \n");
    printf("Press C to clear your flash drive \n");
	
	while(!a_button() && !b_button() && !c_button()){
	//Wait for a button press
	}
	if(a_button()){
		console_clear();
        backup();
	}
	else if(b_button()){
        console_clear();
		restore();
	}
    else if(c_button()){
        console_clear();
		clearDrive();
	}
    msleep(2000);
    return 0;
}
