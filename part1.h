#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <time.h>
#include <bitset>

#define PAGE_SIZE 256
#define PAGE_TABLE_ENTRIES 256
#define FRAME_SIZE 256
#define TLB_ENTRIES 16
#define NUM_OF_FRAMES 256
#define PHYS_MEM_SIZE 65536


#define tlb_rw 0.5
#define mm_rw 100
#define disk_rw 250000

#define num_of_tests 10000

#define MYADDR "myaddresses.txt"


int phys_mem[PHYS_MEM_SIZE];  /// 1 byte 
int page_table[PAGE_TABLE_ENTRIES];
int tlb[TLB_ENTRIES][2];

int num_of_tlb_hits = 0;
int num_of_page_faults = 0;

int final_value;    /* value read from phys mem */

int tlb_front = -1;
int tlb_back = -1;

/* VMM Funcs */


void init_pt();
void init_tlb();


void run_vmm(char* addr);
int get_offset(std::string addr);
int get_page_num(std::string addr);
int find_in_tlb(int page_num);  /*modified*/
int find_in_page_table(int page_table_num); /*modified*/
void update_tlb(int page_num, int frame_num); 

/* Other Funcs*/
void generate_rands();
int fRand(int fMax);
void write_on_file(int data);
int menu();
void print_statistics();
bool check_arg(int argc, char* argv[]);
void swap_in(int frame_num);

 