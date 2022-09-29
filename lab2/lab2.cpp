#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <time.h>

char symbols[27] = "abcdefghijklmnopqrstuvwxyz";

void rand_word(char *my_word, int WORD_LENGTH)
{
   for (int i = 0; i < WORD_LENGTH; i++) 
   {
        int random = rand() % 26;
        my_word[i] = symbols[random];
        //std::cout << my_word[i];
   }
}

void threadFunction(char *my_word, int start, int finish)
{
    for (int i = start; i < finish; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            if (my_word[i] == symbols[j])
            {
                break;
            }
        }
    }
 }

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    const int WORD_LENGTH = 10000;
    const int NUMBER_OF_THREAD = 4;
    int step = WORD_LENGTH / NUMBER_OF_THREAD;
    char my_word[WORD_LENGTH];

    rand_word(my_word, WORD_LENGTH);
    
    double  start_time = clock();

    std::thread thr1(threadFunction, my_word, 0 * step, 1 * step);
    std::thread thr2(threadFunction, my_word, 1 * step, 2 * step);    
    std::thread thr3(threadFunction, my_word, 2 * step, 3 * step);
    std::thread thr4(threadFunction, my_word, 3 * step, 4 * step);
    
    thr1.join();
    thr2.join();
    thr3.join();
    thr4.join();

    double end_time = clock();
    double search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Время работы " << NUMBER_OF_THREAD << " потоков: " << search_time << std::endl;
    
    return 0;
}

