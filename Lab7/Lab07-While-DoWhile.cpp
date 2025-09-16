#include <stdio.h>   // ใช้ printf, scanf
#include <stdlib.h>  // ใช้ rand(), srand()
#include <time.h>    // ใช้ time()

int main() 
{
    srand( time( NULL ) ) ;   // ให้ rand() สุ่มไม่ซ้ำกันในแต่ละครั้ง

    int choice ;              // ตัวเลือกเมนู

    for ( ;; )                // ใช้ for(;;) แทน while(1)
    {
        printf( "Do you want to play game (1=play,-1=exit) :\n" ) ;

        if ( scanf( "%d", &choice ) != 1 )    // ตรวจสอบ input
        {     
            int temp ;
            while ( ( temp = getchar() ) != '\n' && temp != EOF ) ;
            printf( "\nPlease enter only 1 or -1.\n\n" ) ;
            continue ;
        }

        switch ( choice ) 
        {
            case -1 :   // ออกจากโปรแกรม
                printf( "\nSee you again.\n" ) ;
                return 0 ;

            case 1 :    // เล่นเกม
            {
                int points = 100 ;                 // คะแนนเริ่มต้น
                int secret = rand() % 100 + 1 ;    // เลขที่ต้องทาย
                int low = 1, high = 100 ;
                int user ;

                printf( "\n(Score=100)\n" ) ;

                while ( 1 ) 
                {
                    printf( "\nGuess the winning number (%d-%d) :\n", low, high ) ;
                    
                    if ( scanf( "%d", &user ) != 1 )   // กันผู้ใช้ใส่ผิด
                    {   
                        int temp ;
                        while ( ( temp = getchar() ) != '\n' && temp != EOF ) ;
                        printf( "\nPlease enter a number between %d-%d.\n", low, high ) ;
                        continue ;
                    }

                    if ( user == secret ) 
                    {
                        printf( "\nThat is correct! The winning number is %d.\n", secret ) ;
                        printf( "\nScore this game: %d\n\n", points ) ;
                        break ;
                    }

                    points -= 10 ;   // ทายผิด -10 คะแนน
                    if ( user < secret ) 
                    {
                        printf( "\nSorry, the winning number is HIGHER than %d. (Score=%d)\n", user, points ) ;
                        if ( user + 1 > low ) 
                        {
                            low = user + 1 ;
                        }
                    } 
                    else 
                    {
                        printf( "\nSorry, the winning number is LOWER than %d. (Score=%d)\n", user, points ) ;
                        if ( user - 1 < high ) 
                        {
                            high = user - 1 ;
                        }
                    }
                }
                break ;
            }

            default :   // ถ้าไม่ใช่ 1 หรือ -1
                printf( "\nPlease enter only 1 or -1.\n\n" ) ;
                break ;
        }
    }
}
