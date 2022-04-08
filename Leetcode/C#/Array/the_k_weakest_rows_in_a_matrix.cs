using System;
using System.Collections.Generic;
using System.Text;

class the_k_weakest_rows_in_a_matrix
{
    public static int getNbSolder(int[] tab, int target)
    {


        int sPos = 0, ePos = tab.Length - 1, mid;

        while (sPos <= ePos)
        {
            // COmpter le nombre d'itération
            mid = (sPos + ePos) / 2;
            if (tab[mid] == target && (mid == 0 || tab[mid - 1] != target))
                return mid;
            else if (tab[mid] > target)
                sPos = ++mid;
            else
                ePos = --mid;

        }
        return -1;
    }


    public int[] KWeakestRows(int[][] mat, int k)
    {
        int len_mat = mat.Length;
        int len_line = mat[0].Length;
        line[] lines = new line[len_mat];

        int[] res_tab = new int[k]; 

        int solder, i, x, min_index;

        // Obtention du nombre de soldat
        for (i = 0; i < len_mat; i++)
        {
            solder = getNbSolder(mat[i], 0);
            lines[i] = new line((solder == -1) ? len_line : solder, i);
        }

        line line_temp;
        // Tri des lignes en fonction du nombre de soldat
        for (i = 0; i < k; i++)
        {
            min_index = i;
            //min_solder = lines[i].GetNbSolder;
            for (x = i+1; x < len_mat; x++)
            {
                if (lines[x].GetNbSolder < lines[min_index].GetNbSolder || (lines[x].GetNbSolder == lines[min_index].GetNbSolder && lines[x].GetIndex < lines[min_index].GetIndex))
                {
                    min_index = x;
                }
            }

            res_tab[i] = lines[min_index].GetIndex;

            line_temp = lines[i];
            lines[i] = lines[min_index];
            lines[min_index] = line_temp;
        }
        return res_tab;
    }

}


class line
{
    private int _nbSoldat;
    private int _index;

    public line(int nbSoldat, int index)
    {
        _nbSoldat = nbSoldat;
        _index = index;
    }

    public int GetIndex
    {
        get { return _index; }
    }

    public int GetNbSolder
    {
        get { return _nbSoldat; }
    }
}
