using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        int[][] A;
        //формирования матрицы
        static void form_matrix(ref int[][] Matr, int row)
        {

            for (int i = 0; i < Matr.Length; i++)
            { // кол-во элементов в строке 
                int col = Matr.Length;
                Matr[i] = new int[col];
            }
        }
        //формирование матрицы
        static void Create(int[][] Mas)
        {

            for (int i = 0; i < Mas.Length; i++)
                for (int j = 0; j < Mas.Length; j++)
                {
                    if (i == j)
                        Mas[i][j] = Mas.Length;
                    if (j < i)
                        Mas[i][j] = Mas.Length - i+j;

                       }

        }
        //вывод матрицы на экран в DataGridView
        static void Output_Matrix(int[][] Mas, DataGridView dataGridView1)
        {
            //находим макс число строков в стольцов 
            int max_col = Mas[0].Length;
            for (int i = 0; i < Mas.Length; i++)
                if (Mas[i].Length > max_col)
                    max_col = Mas[i].Length;
            dataGridView1.ColumnCount = 0;//очистка
            dataGridView1.ColumnCount = max_col;//количество колонок
            dataGridView1.Rows.Add(Mas.Length);//количество строк
            for (int i = 0; i < max_col; i++)//установка для столбцов 
            {
                //запрещаем менять значения ячеек
                dataGridView1.Columns[i].ReadOnly = true;
                //отключение режима сортировки элементов столбца
                dataGridView1.Columns[i].SortMode = DataGridViewColumnSortMode.NotSortable;
                //заголовок столбцов
                dataGridView1.Columns[i].Name = i.ToString();
                dataGridView1.Columns[i].Width = 30;
            }
            //отображение значений элементов матрицы в DataGridView
            for (int i = 0; i < Mas.Length; i++)
                for (int j = 0; j < Mas[i].Length; j++)
                    //заполнение ячейки 
                    dataGridView1.Rows[i].Cells[j].Value = Mas[i][j].ToString();
            dataGridView1.Visible = true;
        }

      
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            {


                try
                { //количество строк матрицы
                    int str = int.Parse(textBox1.Text);
                    if (str < 1) { MessageBox.Show("Некорректный размер матрицы", "Ошибка!", MessageBoxButtons.OK, MessageBoxIcon.Error); return; }
                    //выделяем память под строки матрицы
                    Array.Resize(ref A, str);
                    //заполняем матрицу случайными числами
                    form_matrix(ref A, str);
                    //выводим матрицу в DataGridView
                    Create(A);
                    //выводим матрицу в DataGridView
                    Output_Matrix(A, dataGridView1);
                }
                catch (FormatException)
                {
                    MessageBox.Show("Вводить только цифры!", "Ошибка!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }

        }
        // удаления матрицы 
        void Delete(ref int[][] mat, int i, int j)
        {
            for (; j < mat[i].Length - 1; j++)
                mat[i][j] = mat[i][j + 1];
            Array.Resize(ref mat, mat.Length - 1);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            float n = A[0].Length / 2;
            dataGridView2.ColumnCount = dataGridView2.RowCount = A[0].Length;
             for (int i = 0; i < A[0].Length; i++)
            {
                 //запрещаем менять значения ячеек
                dataGridView2.Columns[i].ReadOnly = true;
                //отключения режима сортировки эелементов столбца 
                dataGridView2.Columns[i].SortMode = DataGridViewColumnSortMode.NotSortable;
                 //заголовок столбца
                dataGridView2.Columns[i].Name = i.ToString();
                dataGridView2.Columns[i].Width = 25 ; //ширина столбца 
            }
            
            for (int i = 0; i <  A[0].Length; i++)
                for (int j = 0; j < A[i].Length; j++)
                    if (A[i][j] < n)
                        dataGridView2.Rows[i].Cells[j].Value = A[i][j].ToString();
       
        }
    }
}

