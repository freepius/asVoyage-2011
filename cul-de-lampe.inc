# This style must be used only as a separator.
# It allows to make a large separation betwenn two paragraphs, using an asterism.
#
# Author : Mathieu Poisbeau <freepius44@gmai.com>
#


Style Cul-de-lampe
	Category         MainText
	KeepEmpty        1
	Margin           Static
	LatexType        Environment
	LatexName        culdelampe
	HTMLTag          hr
	TopSep           0.5
	BottomSep        0.5
	Align            Center
	AlignPossible    Center
	LabelType        Static
	LabelString      "*** Cul de lampe ***"
	LabelFont
		Family         Roman
		Series         Medium
		Size           Normal
		Color          Blue
	EndFont
	Preamble

%%
% Asterism
%    *
%  *   *
%
\newcommand{\asterism}{
	{\footnotesize
		\raisebox{-.2ex}{
			\setlength{\tabcolsep}{0.5pt}
			\begin{tabular}{@{}cc@{}}
				\multicolumn2c*\\[-1.5ex] *&*
			\end{tabular}
		}
	}
}

%%
% Cul-de-lampe
% with an asterism
%
\newenvironment{culdelampe}{
	\begin{center}
		\vspace{0.75em}
		\asterism
		\vspace{0.75em}
	\end{center}
}

	EndPreamble
End
