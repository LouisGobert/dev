
namespace TimerGenerator
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.m_input_timer_duration = new System.Windows.Forms.TextBox();
            this.m_btn_start_generation = new System.Windows.Forms.Button();
            this.m_rich_code_printer = new System.Windows.Forms.RichTextBox();
            this.m_lbl_timer = new System.Windows.Forms.Label();
            this.m_lbl_nop_max = new System.Windows.Forms.Label();
            this.m_input_max_nop = new System.Windows.Forms.TextBox();
            this.m_lbl_nop = new System.Windows.Forms.Label();
            this.m_rad_btn_one_boucle = new System.Windows.Forms.RadioButton();
            this.m_rad_btn_two_boucle = new System.Windows.Forms.RadioButton();
            this.Option = new System.Windows.Forms.GroupBox();
            this.m_input_var_loop_2 = new System.Windows.Forms.TextBox();
            this.m_input_var_loop_1 = new System.Windows.Forms.TextBox();
            this.m_lbl_var_loop_2 = new System.Windows.Forms.Label();
            this.m_lbl_var_loop_1 = new System.Windows.Forms.Label();
            this.m_input_name_boucle_2 = new System.Windows.Forms.TextBox();
            this.m_input_name_boucle_1 = new System.Windows.Forms.TextBox();
            this.m_lbl_name_boucle_2 = new System.Windows.Forms.Label();
            this.m_lbl_name_boucle_1 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.m_input_time_format = new System.Windows.Forms.ComboBox();
            this.m_input_procedure_name = new System.Windows.Forms.TextBox();
            this.m_lbl_procedure_name = new System.Windows.Forms.Label();
            this.m_lbl_mhz = new System.Windows.Forms.Label();
            this.m_lbl_frequence = new System.Windows.Forms.Label();
            this.m_input_frequence = new System.Windows.Forms.TextBox();
            this.Option.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // m_input_timer_duration
            // 
            this.m_input_timer_duration.AcceptsReturn = true;
            this.m_input_timer_duration.AcceptsTab = true;
            this.m_input_timer_duration.Location = new System.Drawing.Point(164, 16);
            this.m_input_timer_duration.MaxLength = 100;
            this.m_input_timer_duration.Name = "m_input_timer_duration";
            this.m_input_timer_duration.Size = new System.Drawing.Size(58, 23);
            this.m_input_timer_duration.TabIndex = 1;
            this.m_input_timer_duration.Text = "0";
            this.m_input_timer_duration.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.m_input_timer_duration.Validated += new System.EventHandler(this.m_input_timer_duration_Validated);
            // 
            // m_btn_start_generation
            // 
            this.m_btn_start_generation.Location = new System.Drawing.Point(12, 382);
            this.m_btn_start_generation.Name = "m_btn_start_generation";
            this.m_btn_start_generation.Size = new System.Drawing.Size(467, 46);
            this.m_btn_start_generation.TabIndex = 2;
            this.m_btn_start_generation.Text = "Générer le code";
            this.m_btn_start_generation.UseVisualStyleBackColor = true;
            this.m_btn_start_generation.Click += new System.EventHandler(this.m_btn_start_generation_Click);
            // 
            // m_rich_code_printer
            // 
            this.m_rich_code_printer.BackColor = System.Drawing.SystemColors.WindowFrame;
            this.m_rich_code_printer.Cursor = System.Windows.Forms.Cursors.Hand;
            this.m_rich_code_printer.Font = new System.Drawing.Font("Arial Unicode MS", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.m_rich_code_printer.ForeColor = System.Drawing.SystemColors.HighlightText;
            this.m_rich_code_printer.Location = new System.Drawing.Point(494, 12);
            this.m_rich_code_printer.Name = "m_rich_code_printer";
            this.m_rich_code_printer.ReadOnly = true;
            this.m_rich_code_printer.Size = new System.Drawing.Size(294, 426);
            this.m_rich_code_printer.TabIndex = 4;
            this.m_rich_code_printer.Text = "";
            this.m_rich_code_printer.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.m_rich_code_printer_MouseDoubleClick);
            // 
            // m_lbl_timer
            // 
            this.m_lbl_timer.AutoSize = true;
            this.m_lbl_timer.Location = new System.Drawing.Point(68, 20);
            this.m_lbl_timer.Name = "m_lbl_timer";
            this.m_lbl_timer.Size = new System.Drawing.Size(94, 15);
            this.m_lbl_timer.TabIndex = 5;
            this.m_lbl_timer.Text = "Durée du Timer :";
            // 
            // m_lbl_nop_max
            // 
            this.m_lbl_nop_max.AutoSize = true;
            this.m_lbl_nop_max.Location = new System.Drawing.Point(41, 53);
            this.m_lbl_nop_max.Name = "m_lbl_nop_max";
            this.m_lbl_nop_max.Size = new System.Drawing.Size(121, 15);
            this.m_lbl_nop_max.TabIndex = 7;
            this.m_lbl_nop_max.Text = "Nop max par boucle :";
            // 
            // m_input_max_nop
            // 
            this.m_input_max_nop.AcceptsReturn = true;
            this.m_input_max_nop.AcceptsTab = true;
            this.m_input_max_nop.Location = new System.Drawing.Point(164, 49);
            this.m_input_max_nop.MaxLength = 100;
            this.m_input_max_nop.Name = "m_input_max_nop";
            this.m_input_max_nop.Size = new System.Drawing.Size(58, 23);
            this.m_input_max_nop.TabIndex = 8;
            this.m_input_max_nop.Text = "0";
            this.m_input_max_nop.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.m_input_max_nop.Validated += new System.EventHandler(this.m_input_max_nop_Validated);
            // 
            // m_lbl_nop
            // 
            this.m_lbl_nop.AutoSize = true;
            this.m_lbl_nop.Location = new System.Drawing.Point(225, 54);
            this.m_lbl_nop.Name = "m_lbl_nop";
            this.m_lbl_nop.Size = new System.Drawing.Size(28, 15);
            this.m_lbl_nop.TabIndex = 9;
            this.m_lbl_nop.Text = "nop";
            // 
            // m_rad_btn_one_boucle
            // 
            this.m_rad_btn_one_boucle.AutoSize = true;
            this.m_rad_btn_one_boucle.Checked = true;
            this.m_rad_btn_one_boucle.Location = new System.Drawing.Point(27, 22);
            this.m_rad_btn_one_boucle.Name = "m_rad_btn_one_boucle";
            this.m_rad_btn_one_boucle.Size = new System.Drawing.Size(144, 19);
            this.m_rad_btn_one_boucle.TabIndex = 10;
            this.m_rad_btn_one_boucle.TabStop = true;
            this.m_rad_btn_one_boucle.Text = "Structure à une boucle";
            this.m_rad_btn_one_boucle.UseVisualStyleBackColor = true;
            // 
            // m_rad_btn_two_boucle
            // 
            this.m_rad_btn_two_boucle.AutoSize = true;
            this.m_rad_btn_two_boucle.Location = new System.Drawing.Point(286, 22);
            this.m_rad_btn_two_boucle.Name = "m_rad_btn_two_boucle";
            this.m_rad_btn_two_boucle.Size = new System.Drawing.Size(150, 19);
            this.m_rad_btn_two_boucle.TabIndex = 11;
            this.m_rad_btn_two_boucle.TabStop = true;
            this.m_rad_btn_two_boucle.Text = "Structure à deux boucle";
            this.m_rad_btn_two_boucle.UseVisualStyleBackColor = true;
            this.m_rad_btn_two_boucle.CheckedChanged += new System.EventHandler(this.m_rad_btn_two_boucle_CheckedChanged);
            // 
            // Option
            // 
            this.Option.Controls.Add(this.m_input_var_loop_2);
            this.Option.Controls.Add(this.m_input_var_loop_1);
            this.Option.Controls.Add(this.m_lbl_var_loop_2);
            this.Option.Controls.Add(this.m_lbl_var_loop_1);
            this.Option.Controls.Add(this.m_input_name_boucle_2);
            this.Option.Controls.Add(this.m_input_name_boucle_1);
            this.Option.Controls.Add(this.m_lbl_name_boucle_2);
            this.Option.Controls.Add(this.m_lbl_name_boucle_1);
            this.Option.Controls.Add(this.m_rad_btn_one_boucle);
            this.Option.Controls.Add(this.m_rad_btn_two_boucle);
            this.Option.Location = new System.Drawing.Point(13, 201);
            this.Option.Name = "Option";
            this.Option.Size = new System.Drawing.Size(466, 175);
            this.Option.TabIndex = 12;
            this.Option.TabStop = false;
            this.Option.Text = "Option de boucle";
            // 
            // m_input_var_loop_2
            // 
            this.m_input_var_loop_2.Enabled = false;
            this.m_input_var_loop_2.Location = new System.Drawing.Point(301, 141);
            this.m_input_var_loop_2.Name = "m_input_var_loop_2";
            this.m_input_var_loop_2.Size = new System.Drawing.Size(100, 23);
            this.m_input_var_loop_2.TabIndex = 19;
            this.m_input_var_loop_2.Text = "cpt2";
            this.m_input_var_loop_2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.m_input_var_loop_2.Validated += new System.EventHandler(this.m_input_var_loop_2_Validated);
            // 
            // m_input_var_loop_1
            // 
            this.m_input_var_loop_1.Location = new System.Drawing.Point(43, 141);
            this.m_input_var_loop_1.Name = "m_input_var_loop_1";
            this.m_input_var_loop_1.Size = new System.Drawing.Size(100, 23);
            this.m_input_var_loop_1.TabIndex = 18;
            this.m_input_var_loop_1.Text = "cpt1";
            this.m_input_var_loop_1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.m_input_var_loop_1.Validated += new System.EventHandler(this.m_input_var_loop_1_Validated);
            // 
            // m_lbl_var_loop_2
            // 
            this.m_lbl_var_loop_2.AutoSize = true;
            this.m_lbl_var_loop_2.Enabled = false;
            this.m_lbl_var_loop_2.Location = new System.Drawing.Point(306, 124);
            this.m_lbl_var_loop_2.Name = "m_lbl_var_loop_2";
            this.m_lbl_var_loop_2.Size = new System.Drawing.Size(91, 15);
            this.m_lbl_var_loop_2.TabIndex = 17;
            this.m_lbl_var_loop_2.Text = "Vriable boucle 2";
            // 
            // m_lbl_var_loop_1
            // 
            this.m_lbl_var_loop_1.AutoSize = true;
            this.m_lbl_var_loop_1.Location = new System.Drawing.Point(45, 124);
            this.m_lbl_var_loop_1.Name = "m_lbl_var_loop_1";
            this.m_lbl_var_loop_1.Size = new System.Drawing.Size(96, 15);
            this.m_lbl_var_loop_1.TabIndex = 16;
            this.m_lbl_var_loop_1.Text = "Variable boucle 1";
            // 
            // m_input_name_boucle_2
            // 
            this.m_input_name_boucle_2.Enabled = false;
            this.m_input_name_boucle_2.Location = new System.Drawing.Point(301, 75);
            this.m_input_name_boucle_2.Name = "m_input_name_boucle_2";
            this.m_input_name_boucle_2.Size = new System.Drawing.Size(100, 23);
            this.m_input_name_boucle_2.TabIndex = 15;
            this.m_input_name_boucle_2.Text = "boucle2";
            this.m_input_name_boucle_2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.m_input_name_boucle_2.Validated += new System.EventHandler(this.m_input_name_boucle_2_Validated);
            // 
            // m_input_name_boucle_1
            // 
            this.m_input_name_boucle_1.Location = new System.Drawing.Point(43, 76);
            this.m_input_name_boucle_1.Name = "m_input_name_boucle_1";
            this.m_input_name_boucle_1.Size = new System.Drawing.Size(100, 23);
            this.m_input_name_boucle_1.TabIndex = 14;
            this.m_input_name_boucle_1.Text = "boucle1";
            this.m_input_name_boucle_1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.m_input_name_boucle_1.Validated += new System.EventHandler(this.m_input_name_boucle_1_Validated);
            // 
            // m_lbl_name_boucle_2
            // 
            this.m_lbl_name_boucle_2.AutoSize = true;
            this.m_lbl_name_boucle_2.Enabled = false;
            this.m_lbl_name_boucle_2.Location = new System.Drawing.Point(310, 58);
            this.m_lbl_name_boucle_2.Name = "m_lbl_name_boucle_2";
            this.m_lbl_name_boucle_2.Size = new System.Drawing.Size(82, 15);
            this.m_lbl_name_boucle_2.TabIndex = 13;
            this.m_lbl_name_boucle_2.Text = "Nom boucle 2";
            // 
            // m_lbl_name_boucle_1
            // 
            this.m_lbl_name_boucle_1.AutoSize = true;
            this.m_lbl_name_boucle_1.Location = new System.Drawing.Point(52, 58);
            this.m_lbl_name_boucle_1.Name = "m_lbl_name_boucle_1";
            this.m_lbl_name_boucle_1.Size = new System.Drawing.Size(82, 15);
            this.m_lbl_name_boucle_1.TabIndex = 12;
            this.m_lbl_name_boucle_1.Text = "Nom boucle 1";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.m_input_time_format);
            this.groupBox1.Controls.Add(this.m_input_procedure_name);
            this.groupBox1.Controls.Add(this.m_lbl_procedure_name);
            this.groupBox1.Controls.Add(this.m_lbl_mhz);
            this.groupBox1.Controls.Add(this.m_lbl_frequence);
            this.groupBox1.Controls.Add(this.m_input_frequence);
            this.groupBox1.Controls.Add(this.m_lbl_timer);
            this.groupBox1.Controls.Add(this.m_input_timer_duration);
            this.groupBox1.Controls.Add(this.m_lbl_nop);
            this.groupBox1.Controls.Add(this.m_input_max_nop);
            this.groupBox1.Controls.Add(this.m_lbl_nop_max);
            this.groupBox1.Location = new System.Drawing.Point(13, 27);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(466, 168);
            this.groupBox1.TabIndex = 13;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Option générale";
            // 
            // m_input_time_format
            // 
            this.m_input_time_format.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.m_input_time_format.FormattingEnabled = true;
            this.m_input_time_format.Items.AddRange(new object[] {
            "µs",
            "ms",
            "s"});
            this.m_input_time_format.Location = new System.Drawing.Point(225, 17);
            this.m_input_time_format.Name = "m_input_time_format";
            this.m_input_time_format.Size = new System.Drawing.Size(60, 23);
            this.m_input_time_format.TabIndex = 15;
            this.m_input_time_format.SelectedIndexChanged += new System.EventHandler(this.m_input_time_format_SelectedIndexChanged);
            // 
            // m_input_procedure_name
            // 
            this.m_input_procedure_name.Location = new System.Drawing.Point(164, 117);
            this.m_input_procedure_name.Name = "m_input_procedure_name";
            this.m_input_procedure_name.Size = new System.Drawing.Size(89, 23);
            this.m_input_procedure_name.TabIndex = 14;
            this.m_input_procedure_name.Text = "tempo";
            this.m_input_procedure_name.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.m_input_procedure_name.Validated += new System.EventHandler(this.m_input_procedure_name_Validated);
            // 
            // m_lbl_procedure_name
            // 
            this.m_lbl_procedure_name.AutoSize = true;
            this.m_lbl_procedure_name.Location = new System.Drawing.Point(37, 121);
            this.m_lbl_procedure_name.Name = "m_lbl_procedure_name";
            this.m_lbl_procedure_name.Size = new System.Drawing.Size(125, 15);
            this.m_lbl_procedure_name.TabIndex = 13;
            this.m_lbl_procedure_name.Text = "Nom de la procédure :";
            // 
            // m_lbl_mhz
            // 
            this.m_lbl_mhz.AutoSize = true;
            this.m_lbl_mhz.Location = new System.Drawing.Point(225, 86);
            this.m_lbl_mhz.Name = "m_lbl_mhz";
            this.m_lbl_mhz.Size = new System.Drawing.Size(32, 15);
            this.m_lbl_mhz.TabIndex = 12;
            this.m_lbl_mhz.Text = "MHz";
            // 
            // m_lbl_frequence
            // 
            this.m_lbl_frequence.AutoSize = true;
            this.m_lbl_frequence.Location = new System.Drawing.Point(94, 86);
            this.m_lbl_frequence.Name = "m_lbl_frequence";
            this.m_lbl_frequence.Size = new System.Drawing.Size(68, 15);
            this.m_lbl_frequence.TabIndex = 11;
            this.m_lbl_frequence.Text = "Fréquence :";
            // 
            // m_input_frequence
            // 
            this.m_input_frequence.Location = new System.Drawing.Point(164, 82);
            this.m_input_frequence.Name = "m_input_frequence";
            this.m_input_frequence.Size = new System.Drawing.Size(58, 23);
            this.m_input_frequence.TabIndex = 10;
            this.m_input_frequence.Text = "0";
            this.m_input_frequence.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.m_input_frequence.Validated += new System.EventHandler(this.m_input_frequence_Validated);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.Option);
            this.Controls.Add(this.m_rich_code_printer);
            this.Controls.Add(this.m_btn_start_generation);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "Timer Nop Generator";
            this.Option.ResumeLayout(false);
            this.Option.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.TextBox m_input_timer_duration;
        private System.Windows.Forms.Button m_btn_start_generation;
        private System.Windows.Forms.RichTextBox m_rich_code_printer;
        private System.Windows.Forms.Label m_lbl_timer;
        private System.Windows.Forms.Label m_lbl_nop_max;
        private System.Windows.Forms.TextBox m_input_max_nop;
        private System.Windows.Forms.Label m_lbl_nop;
        private System.Windows.Forms.RadioButton m_rad_btn_one_boucle;
        private System.Windows.Forms.RadioButton m_rad_btn_two_boucle;
        private System.Windows.Forms.GroupBox Option;
        private System.Windows.Forms.Label m_lbl_name_boucle_1;
        private System.Windows.Forms.Label m_lbl_name_boucle_2;
        private System.Windows.Forms.TextBox m_input_name_boucle_2;
        private System.Windows.Forms.TextBox m_input_name_boucle_1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label m_lbl_frequence;
        private System.Windows.Forms.TextBox m_input_frequence;
        private System.Windows.Forms.Label m_lbl_mhz;
        private System.Windows.Forms.TextBox m_input_var_loop_2;
        private System.Windows.Forms.TextBox m_input_var_loop_1;
        private System.Windows.Forms.Label m_lbl_var_loop_2;
        private System.Windows.Forms.Label m_lbl_var_loop_1;
        private System.Windows.Forms.TextBox m_input_procedure_name;
        private System.Windows.Forms.Label m_lbl_procedure_name;
        private System.Windows.Forms.ComboBox m_input_time_format;
    }
}

