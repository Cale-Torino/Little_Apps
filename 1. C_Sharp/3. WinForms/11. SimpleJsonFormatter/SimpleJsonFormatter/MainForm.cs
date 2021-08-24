using System;
using System.Drawing;
using System.Windows.Forms;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using ScintillaNET;
using SimpleJsonFormatter.Properties;

namespace SimpleJsonFormatter
{
    public partial class MainForm : Form
    {
        private int _maxLineNumberCharLength;
        private int _lastCaretPos;

        public MainForm()
        {
            InitializeComponent();
            InitializeScintilla();
            
            btnAutoPasteOnLoad.Checked = Properties.Settings.Default.AutoPasteOnLoad;

            if (btnAutoPasteOnLoad.Checked)
            {
                btnAutoPasteOnLoad.Image = Resources.chkbx1;

                if (Clipboard.ContainsText())
                {
                    txtInput.Text = Clipboard.GetText(TextDataFormat.UnicodeText);
                }
            }
            else
            {
                btnAutoPasteOnLoad.Image = Resources.chkbx0;
            }
        }

        private void InitializeScintilla()
        {
            scnOutput.Lexer = Lexer.Json;
            scnOutput.SetKeywords(0, @"true false");

            #region Syntax Colors

            scnOutput.Styles[Style.Json.Number].ForeColor         = Color.DodgerBlue;
            scnOutput.Styles[Style.Json.BlockComment].ForeColor   = Color.Green;
            scnOutput.Styles[Style.Json.LineComment].ForeColor    = Color.Green;
            scnOutput.Styles[Style.Json.Default].ForeColor        = Color.Black;
            scnOutput.Styles[Style.Json.PropertyName].ForeColor   = Color.Gray;
            scnOutput.Styles[Style.Json.Error].ForeColor          = Color.Red;
            scnOutput.Styles[Style.Json.Uri].ForeColor            = Color.MediumBlue;
            scnOutput.Styles[Style.Json.Uri].Underline            = true;
            scnOutput.Styles[Style.Json.CompactIRI].ForeColor     = Color.MediumBlue;
            scnOutput.Styles[Style.Json.CompactIRI].Underline     = true;
            scnOutput.Styles[Style.Json.EscapeSequence].ForeColor = Color.BurlyWood;
            scnOutput.Styles[Style.Json.Keyword].ForeColor        = Color.Blue;
            scnOutput.Styles[Style.Json.Operator].ForeColor       = Color.Black;
            scnOutput.Styles[Style.Json.String].ForeColor         = Color.OrangeRed;

            #endregion Syntax Colors

            foreach (var style in scnOutput.Styles)
            {
                style.Font = "Courier New";
                style.SizeF = 12;
            }

            #region Folding

            scnOutput.AutomaticFold = AutomaticFold.Show | AutomaticFold.Click | AutomaticFold.Change;

            // Instruct the lexer to calculate folding
            scnOutput.SetProperty("fold", "1");
            scnOutput.SetProperty("fold.compact", "1");

            // Configure a margin to display folding symbols
            scnOutput.Margins[2].Type      = MarginType.Symbol;
            scnOutput.Margins[2].Mask      = Marker.MaskFolders;
            scnOutput.Margins[2].Sensitive = true;
            scnOutput.Margins[2].Width     = 20;

            // Set colors for all folding markers
            for (int i = 25; i <= 31; i++)
            {
                scnOutput.Markers[i].SetForeColor(SystemColors.ControlLightLight);
                scnOutput.Markers[i].SetBackColor(SystemColors.ControlDark);
            }

            // Configure folding markers with respective symbols
            scnOutput.Markers[Marker.Folder].Symbol        = MarkerSymbol.BoxPlus;
            scnOutput.Markers[Marker.FolderOpen].Symbol    = MarkerSymbol.BoxMinus;
            scnOutput.Markers[Marker.FolderEnd].Symbol     = MarkerSymbol.BoxPlusConnected;
            scnOutput.Markers[Marker.FolderMidTail].Symbol = MarkerSymbol.TCorner;
            scnOutput.Markers[Marker.FolderOpenMid].Symbol = MarkerSymbol.BoxMinusConnected;
            scnOutput.Markers[Marker.FolderSub].Symbol     = MarkerSymbol.VLine;
            scnOutput.Markers[Marker.FolderTail].Symbol    = MarkerSymbol.LCorner;

            // Enable automatic folding
            scnOutput.AutomaticFold = AutomaticFold.Show | AutomaticFold.Click | AutomaticFold.Change;

            #endregion Folding

            #region Line Numbers

            scnOutput.Styles[Style.LineNumber].ForeColor = Color.LightSlateGray;

            #endregion Line Numbers

            #region Whitespace

            scnOutput.WhitespaceSize = 3;
            scnOutput.SetWhitespaceForeColor(true, Color.FromArgb(200, 40, 40));

            #endregion Whitespace

            #region Brace Matching

            scnOutput.IndentationGuides = IndentView.LookBoth;
            scnOutput.Styles[Style.BraceLight].BackColor = Color.LightGray;
            scnOutput.Styles[Style.BraceLight].ForeColor = Color.BlueViolet;
            scnOutput.Styles[Style.BraceBad].ForeColor   = Color.Red;

            #endregion Brace Matching

            scnOutput.Margins[0].Width = 16;

            #if DEBUG
            txtInput.Text = @"{""clients"":[{""id"": ""59761c23b30d971669fb42ff"",""isActive"": true,""age"": 36,""name"": ""Dunlap Hubbard"",""gender"": ""male"",""company"": ""CEDWARD"",""email"": ""dunlaphubbard@cedward.com"",""website"":""http://www.example.com"",""phone"": ""+1 (890) 543-2508"",""address"": ""169 Rutledge Street, Konterra, Northern Mariana Islands, 8551""},{""id"": ""59761c233d8d0f92a6b0570d"",""isActive"": false,""age"": 24,""name"": ""Kirsten Sellers"",""gender"": ""female"",""company"": ""EMERGENT"",""email"": ""kirstensellers@emergent.com"",""website"":""http://www.example.com"",""phone"": ""+1 (831) 564-2190"",""address"": ""886 Gallatin Place, Fannett, Arkansas, 4656""},{""id"": ""59761c23fcb6254b1a06dad5"",""isActive"": true,""age"": 30,""name"": ""Acosta Robbins"",""gender"": ""male"",""company"": ""ORGANICA"",""email"": ""acostarobbins@organica.com"",""website"":""http://www.example.com"",""phone"": ""+1 (882) 441-3367"",""address"": ""697 Linden Boulevard, Sattley, Idaho, 1035""}]}";
            #endif
        }

        private void txtInput_TextChanged(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(txtInput.Text?.Trim()))
            {
                scnOutput.Text = "";
            }
            else
            {
                try
                {
                    scnOutput.Text = JToken.Parse(txtInput.Text).ToString(Formatting.Indented);
                }
                catch (JsonReaderException ex)
                {
                    scnOutput.Text = "!Error!\n" + ex.Message;
                }
            }
        }

        private void scnOutput_TextChanged(object sender, EventArgs e)
        {
            // Did the number of characters in the line number display change?
            // i.e. nnn VS nn, or nnnn VS nn, etc...
            var maxLineNumberCharLength = scnOutput.Lines.Count.ToString().Length;
            if (maxLineNumberCharLength == this._maxLineNumberCharLength)
                return;

            // Calculate the width required to display the last line number
            // and include some padding for good measure.
            const int padding = 2;
            scnOutput.Margins[0].Width = scnOutput.TextWidth(Style.LineNumber, new string('9', maxLineNumberCharLength + 1)) + padding;
            this._maxLineNumberCharLength = maxLineNumberCharLength;
        }

        private void scnOutput_UpdateUI(object sender, UpdateUIEventArgs e)
        {
            // Has the caret changed position?
            var caretPos = scnOutput.CurrentPosition;
            if (_lastCaretPos != caretPos)
            {
                _lastCaretPos = caretPos;
                var bracePos1 = -1;
                var bracePos2 = -1;

                // Is there a brace to the left or right?
                if (caretPos > 0 && IsBrace(scnOutput.GetCharAt(caretPos - 1)))
                    bracePos1 = (caretPos - 1);
                else if (IsBrace(scnOutput.GetCharAt(caretPos)))
                    bracePos1 = caretPos;

                if (bracePos1 >= 0)
                {
                    // Find the matching brace
                    bracePos2 = scnOutput.BraceMatch(bracePos1);
                    if (bracePos2 == Scintilla.InvalidPosition)
                    {
                        scnOutput.BraceBadLight(bracePos1);
                        scnOutput.HighlightGuide = 0;
                    }
                    else
                    {
                        scnOutput.BraceHighlight(bracePos1, bracePos2);
                        scnOutput.HighlightGuide = scnOutput.GetColumn(bracePos1);
                    }
                }
                else
                {
                    // Turn off brace matching
                    scnOutput.BraceHighlight(Scintilla.InvalidPosition, Scintilla.InvalidPosition);
                    scnOutput.HighlightGuide = 0;
                }
            }
        }

        private static bool IsBrace(int c)
        {
            switch (c)
            {
                case '(':
                case ')':
                case '[':
                case ']':
                case '{':
                case '}':
                case '<':
                case '>':
                    return true;
                default:
                    return false;
            }
        }

        private void btnCollapseAll_Click(object sender, EventArgs e)
        {
            foreach (var line in scnOutput.Lines)
            {
                line.FoldLine(FoldAction.Contract);
            }
        }

        private void btnExapndAll_Click(object sender, EventArgs e)
        {
            foreach (var line in scnOutput.Lines)
            {
                line.FoldLine(FoldAction.Expand);
            }
        }

        private void btnShowWhitespace_CheckedChanged(object sender, EventArgs e)
        {
            switch (btnShowWhitespace.Checked)
            {
                case true:
                    btnShowWhitespace.Image = Resources.chkbx1;
                    scnOutput.ViewWhitespace = WhitespaceMode.VisibleAlways;
                    break;
                case false:
                    btnShowWhitespace.Image = Resources.chkbx0;
                    scnOutput.ViewWhitespace = WhitespaceMode.Invisible;
                    break;
            }
        }

        private void btnPaste_Click(object sender, EventArgs e)
        {
            if (Clipboard.ContainsText())
            {
                txtInput.Text = Clipboard.GetText(TextDataFormat.UnicodeText);
            }
        }

        private void btnAutoPasteOnLoad_CheckedChanged(object sender, EventArgs e)
        {
            Properties.Settings.Default.AutoPasteOnLoad = btnAutoPasteOnLoad.Checked;
            Properties.Settings.Default.Save();

            switch (btnAutoPasteOnLoad.Checked)
            {
                case true:
                    btnAutoPasteOnLoad.Image = Resources.chkbx1;
                    break;
                case false:
                    btnAutoPasteOnLoad.Image = Resources.chkbx0;
                    break;
            }
        }
    }
}
