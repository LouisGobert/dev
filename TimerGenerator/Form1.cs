using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TimerGenerator
{
    public partial class Form1 : Form
    {
        private enum E_T_FORMAT : ushort {MICROSEC, MINISEC, SEC};
        private E_T_FORMAT T_FORMAT;

        public Form1()
        {
            InitializeComponent();

            // Le format de base est en us
            T_FORMAT = E_T_FORMAT.MICROSEC;
            m_input_time_format.SelectedIndex = 0;
        }



        private void m_rich_code_printer_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            Clipboard.SetData(DataFormats.Text, m_rich_code_printer.Text);
            MessageBox.Show("Copier");
        }

        private void m_input_timer_duration_Validated(object sender, EventArgs e)
        {
            try
            {               
                double value = (T_FORMAT == E_T_FORMAT.MICROSEC) ? value = int.Parse(m_input_timer_duration.Text): double.Parse(m_input_timer_duration.Text);

                if (value < 0)
                {
                    MessageBox.Show("La durée dois être positive.", "Erreur de durée", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    m_input_timer_duration.Text = "0";
                }
                else
                    m_input_timer_duration.Text = value.ToString();
            }
            catch
            {
                MessageBox.Show("La durée n'est pas correct.", "Erreur de durée", MessageBoxButtons.OK, MessageBoxIcon.Error);
                m_input_timer_duration.Text = "0";
            }
            
        }

        private void m_input_max_nop_Validated(object sender, EventArgs e)
        {
            try
            {
                int value = int.Parse(m_input_max_nop.Text);
                if (value < 0)
                    m_input_max_nop.Text = "0";
                else
                    m_input_max_nop.Text = value.ToString();

            } catch
            {
                MessageBox.Show("Le nombre de NOP n'est pas correct", "Erreur du nombre de NOP", MessageBoxButtons.OK, MessageBoxIcon.Error);
                m_input_max_nop.Text = "0";

            }
                

        }

        private void m_input_frequence_Validated(object sender, EventArgs e)
        {

      
            try
            {
                double value = double.Parse(m_input_frequence.Text);
                if (value < 0)
                    m_input_frequence.Text = "0";
                else
                    m_input_frequence.Text = value.ToString();
            } catch
            {
                m_input_frequence.Text = "0";
                MessageBox.Show("La fréquence n'est pas corrcet.", "Erreur de fréquence", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }



        private void m_rad_btn_two_boucle_CheckedChanged(object sender, EventArgs e)
        {
            m_lbl_name_boucle_2.Enabled = m_rad_btn_two_boucle.Checked;
            m_input_name_boucle_2.Enabled = m_rad_btn_two_boucle.Checked;
            m_lbl_var_loop_2.Enabled = m_rad_btn_two_boucle.Checked;
            m_input_var_loop_2.Enabled = m_rad_btn_two_boucle.Checked;
            
        }

        private void m_input_name_boucle_1_Validated(object sender, EventArgs e)
        {
            m_input_name_boucle_1.Text = m_input_name_boucle_1.Text.Replace(" ", "_");
        }

        private void m_input_var_loop_1_Validated(object sender, EventArgs e)
        {
            m_input_var_loop_1.Text = m_input_var_loop_1.Text.Replace(" ", "_");
        }

        private void m_input_name_boucle_2_Validated(object sender, EventArgs e)
        {
            m_input_name_boucle_2.Text = m_input_name_boucle_2.Text.Replace(" ", "_");
        }

        private void m_input_var_loop_2_Validated(object sender, EventArgs e)
        {
            m_input_var_loop_2.Text = m_input_var_loop_2.Text.Replace(" ", "_");
        }
        private void m_input_procedure_name_Validated(object sender, EventArgs e)
        {
            m_input_procedure_name.Text = m_input_procedure_name.Text.Replace(" ", "_");
        }


        private void m_input_time_format_SelectedIndexChanged(object sender, EventArgs e)
        {

            switch (m_input_time_format.SelectedIndex)
            {
                case 0:
                    if (T_FORMAT == E_T_FORMAT.MINISEC)
                        m_input_timer_duration.Text = (double.Parse(m_input_timer_duration.Text) * 1000).ToString();
                    else if (T_FORMAT == E_T_FORMAT.SEC)
                        m_input_timer_duration.Text = (double.Parse(m_input_timer_duration.Text) * 1000000).ToString();

                    T_FORMAT = E_T_FORMAT.MICROSEC;
                    break;


                case 1:
                    if (T_FORMAT == E_T_FORMAT.MICROSEC)
                        m_input_timer_duration.Text = (double.Parse(m_input_timer_duration.Text) / 1000).ToString();
                    else if (T_FORMAT == E_T_FORMAT.SEC)
                        m_input_timer_duration.Text = (double.Parse(m_input_timer_duration.Text) * 1000).ToString();

                    T_FORMAT = E_T_FORMAT.MINISEC;
                    break;

                case 2:
                    if (T_FORMAT == E_T_FORMAT.MICROSEC)
                        m_input_timer_duration.Text = (double.Parse(m_input_timer_duration.Text) / 1000000).ToString();
                    else if (T_FORMAT == E_T_FORMAT.MINISEC)
                        m_input_timer_duration.Text = (double.Parse(m_input_timer_duration.Text) / 1000).ToString();

                    T_FORMAT = E_T_FORMAT.SEC;
                    break;
                    break;
            }
        }

        /////////////////////////////////////////////////////////////////////////////////
        ///                                                                            //
        ///                     LANCEMENT DU CALCUL DU TEMPS                           //
        ///                                                                            //
        ///////////////////////////////////////////////////////////////////////////////// 

        private void m_btn_start_generation_Click(object sender, EventArgs e)
        {
            // Vérification des données fournies
            int max_nop = int.Parse(m_input_max_nop.Text);
            double duree = double.Parse(m_input_timer_duration.Text);
            double frequence = double.Parse(m_input_frequence.Text);

            // Transformation de la durée en micro seconde
            if (T_FORMAT != E_T_FORMAT.MICROSEC)
            {
                if (T_FORMAT == E_T_FORMAT.MINISEC) duree *= 1000;
                else duree *= 1000000;
            }


            if (duree == 0 || frequence == 0)
            {
                MessageBox.Show("Les données fournies ne sont pas correct.", 
                                "Erreur de donnée",
                                MessageBoxButtons.OK, 
                                MessageBoxIcon.Error);
                return;
            }

            // Check le type de structure
            if (m_rad_btn_one_boucle.Checked)
            {
                string result;
                if (Generate.GenerateOneLoop(duree, frequence, max_nop, out result, 
                    m_input_name_boucle_1.Text, m_input_var_loop_1.Text, m_input_procedure_name.Text))
                {
                    m_rich_code_printer.Text = result;
                } else
                {
                    // Pas de solutioj trouvée
                    MessageBox.Show("Pas de solution trouvée",
                                "Insolvable",
                                MessageBoxButtons.OK,
                                MessageBoxIcon.Error);
                }

            } else
            {
                string result;
                if (Generate.GenerateTwoLoop(duree, frequence, max_nop, out result,
                    m_input_name_boucle_1.Text, m_input_var_loop_1.Text,
                    m_input_procedure_name.Text, m_input_name_boucle_2.Text, 
                    m_input_var_loop_2.Text))
                {
                    m_rich_code_printer.Text = result;
                }
                else
                {
                    // Pas de solutioj trouvée
                    MessageBox.Show("Pas de solution trouvée",
                                "Insolvable",
                                MessageBoxButtons.OK,
                                MessageBoxIcon.Error);
                }
            }
        }
    }
}
