using sqlite_example_library;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace sqlite_example
{
    //https://www.connectionstrings.com/sqlite/
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            LoadPeopleList();
        }

        List<PersonClass> people = new List<PersonClass>();


        private void LoadPeopleList()
        {
            people = SqliteDataAccessClass.LoadPeople();

            WireUpPeopleList();
        }

        private void WireUpPeopleList()
        {
            listPeopleListBox.DataSource = null;
            listPeopleListBox.DataSource = people;
            listPeopleListBox.DisplayMember = "full_name";
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void addPersonButton_Click_1(object sender, EventArgs e)
        {
            PersonClass p = new PersonClass();

            p.first_name = firstNameText.Text;
            p.last_name = lastNameText.Text;

            SqliteDataAccessClass.SavePerson(p);

            firstNameText.Text = "";
            lastNameText.Text = "";
        }

        private void refreshListButton_Click_1(object sender, EventArgs e)
        {
            LoadPeopleList();
        }
    }
}
