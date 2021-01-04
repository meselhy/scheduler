#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#define LINE_MAX 1024

using namespace std;

struct node
{
  int data;
  struct node *next;
};


struct node *createNode (int);
struct node *insertBack (struct node *, int);
void display (struct node *);
int countLenght (struct node *);
void getFcfs (int a[], int n);
void getRR(int brst[], int arvl[], int q, int n);


int
main ()
{

  int x;
  int y;
  cout << (" \n") << endl;
  cout << ("Messelhi's CPU Scheduler Simulator\n\n") << endl;
  cout << ("Please select one option\n\n"
     "1. Scheduling Method\n"
     "2. Preemptive Mode N/A\n"
     "3. Non-Preemptive Mode N/A\n"
     "4. Show Results N/A\n" "5. End Program\n\n");
  scanf ("%d", &x);

  FILE *ip;
  char line[LINE_MAX];
  int burstTime, arivalTime, priorityTime;
  struct node *headerBrst = NULL;
  struct node *headerArvl = NULL;
  struct node *headerPir = NULL;

  if ((ip = fopen ("input.txt", "r")) == NULL)
    {
      cout << " ABRACADABRA, no input file , exiting ..." << endl;
    }

  while (fgets (line, LINE_MAX, ip) != NULL)
    {
      sscanf (line, "%d:%d:%d\n", &burstTime, &arivalTime, &priorityTime);
      headerBrst = insertBack (headerBrst, burstTime);
      headerArvl = insertBack (headerArvl, arivalTime);
      headerPir = insertBack (headerPir, priorityTime);
      //display(headerBrst);
    }
  fclose (ip);

  if (x == 1)
    {

      cout << ("Please select scheduling method\n"
         "1. First Come First Served\n"
         "2. Round Robin N/A\n" "3. Priority N/A\n" "4. SJFS N/A\n\n");
      scanf ("%d", &y);

      switch (y)
  {
  case 1:
    {

      int brs = countLenght (headerBrst);
      int x[brs];
      int i = 0;
      node *temp = headerBrst;
      while (temp != NULL)
        {
    x[i++] = temp->data;
    temp = temp->next;
        }

      int m = sizeof x / sizeof x[brs];
      cout << " FCFS is selected \n" << endl;
      getFcfs (x, m);

    }
    break;

  case 2:
    {
      int brs = countLenght (headerBrst);
      int x[brs];
      int i = 0;
      node *temp = headerBrst;
      while (temp != NULL)
        {
    x[i++] = temp->data;
    temp = temp->next;
        }

      int arv = countLenght (headerArvl);
      int y[arv];
      int j = 0;
      node *temp2 = headerArvl;
      while (temp2 != NULL)
        {
    y[j++] = temp2->data;
    temp2 = temp2->next;
        }

      int k = sizeof y / sizeof y[arv];
      int q;
      cout << " Please enter quantum time \n" << endl;
      scanf ("%d", &q);
      cout << " Round Robin is selected \n" << endl;
      getRR (x,y,q,k);
      break;
    }
  case 3:
    {
      cout << "ABRACADABRA\n" << endl;
      break;
    }
  case 4:
    {
      cout << "ABRACADABRA\n" << endl;
      break;
    }
  }

    }
  if (x == 3 || x == 4)
    {
      cout << "ABRACADABRA\n" << endl;
    }

  if (x == 5)
    {
      cout << "Exiting ... \n" << endl;
      return 0;
    }

  return 0;
}

void
getFcfs (int a[], int n)
{
  int b[n];
  b[0] = 0;
  double summ = 0;
  int i = 1;
  while (i < n)
    {
      b[i] = b[i - 1] + a[i - 1];
      i++;
    }

  printf ("\nProcess\t\tWaiting Time\n");
  FILE *op = fopen ("output.txt", "w");
  fprintf(op, "Process\t\tWaiting Time\n");
  for (int i = 0; i < n; i++)
    {
      cout << "  " << "P" << i + 1 << "\t\t   " << b[i] << endl;
      summ += b[i];
      fprintf(op, "%s%d\t\t  %d\n","  P",i+1, b[i]);
    }
  cout << "\nAverage waiting time = " << summ / n << " ms\n" << endl;
  fprintf(op,"%s%.2f%s", "\nAverage waiting time = ", summ/n, " ms");
  fclose (op);
}

void
getRR (int brst[], int arvl[], int q, int n)
{
  int rem[n];
  int wt[n];
  int comp[n];
  int t = 0;
  int arrival = 0;
  double summ = 0;

  for (int i = 0; i < n; i++)
    {
      rem[i] = brst[i];
    }
  if (arvl[0] != 0)
    {
      cout << "Arrival time is incorrect" << endl;
      return;
    }

  while (true)
    {
      bool tmm = true;
      int i = 0;
      while (i < n)
  {
    if (rem[i] > 0)
      {
        tmm = false;
        if (rem[i] > q && arvl[i] <= arrival)
    {
      t += q;
      rem[i] -= q;
      arrival++;
    }
        else
    {
      if (arvl[i] <= arrival)
        {
          arrival++;
          t += rem[i];
          rem[i] = 0;
          comp[i] = t;
        }
    }
      }
    i++;
  }
      if (tmm == true)
  break;
    }
  for (int i = 0; i < n; i++)
    {
      wt[i] = comp[i] - arvl[i] - brst[i];
    }
  printf ("\nProcess\t\tWaiting Time\n");
  for (int i = 0; i < n; i++)
    {
      cout << "  " << "P" << i + 1 << "\t\t   " << wt[i] << endl;
      summ += wt[i];
    }
  cout << "\nAverage waiting time = " << summ / n << " ms\n" << endl;
}

struct node *
createNode (int item)
{
  struct node *temp;
  temp = (struct node *) malloc (sizeof (node));
  temp->data = item;
  temp->next = NULL;
  return temp;
}

struct node *
insertBack (struct node *header, int data)
{

  struct node *temp = createNode (data);
  struct node *headertemp;

  if (header == NULL)
    {
      header = temp;
      return header;
    }

  headertemp = header;

  while (headertemp->next != NULL)
    headertemp = headertemp->next;

  headertemp->next = temp;

  return header;
}

void
display (struct node *header)
{
  if (header == NULL)
    cout << "List is empty" << endl;

  struct node *temp = header;

  while (temp != NULL)
    {
      cout << temp->data << " --> ";
      temp = temp->next;
    }
  cout << endl;
}

int
countLenght (struct node *header)
{
  struct node *temp = header;
  int count = 0;
  while (temp != NULL)
    {
      count++;
      temp = temp->next;
    }
  return count;
}
