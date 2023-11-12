using System;

bool orzetlen(int[] fal, int N, int kezdes)
{
    bool van = false;

    int i = kezdes;

    while (!van && i <= N - 2)
    {
        if (fal[i] == 0 && fal[i+1] == 0 && fal[i+2] == 0)
        { van = true; }
        i++;
    }

    return van;
}

int N, db=0;

Console.Error.Write("Add meg az N-t! ");
N = Int32.Parse(Console.ReadLine());

int[] fal = new int[N];

for (int i = 1; i <= N; i++)
{
    Console.Error.WriteLine("fal[i]: ");
    fal[i-1] = Int32.Parse(Console.ReadLine());
}

for (int i = 1; i <= N; i++)
    if (orzetlen(fal, N, i))
        db++;


Console.WriteLine(db);
