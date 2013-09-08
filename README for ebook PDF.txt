WARNING :
    -> Conflict between "titlesec" and "hyperref". So don't use "titlesec" !
    -> Use "bookmark" package with "numbered" option to resolve the missing of "chapter" level
       (there are parts and sections without chapter).

Below, the nasty code to resolve it :

\usepackage[numbered]{bookmark}

\renewcommand\part{%
  \if@openright
    \cleardoublepage
  \else
    \clearpage
  \fi
  \thispagestyle{empty}%
  \if@twocolumn
    \onecolumn
    \@tempswatrue
  \else
    \@tempswafalse
  \fi
  \null\vfil
  \secdef\@part\@spart}

\def\@part[#1]#2{%
    \ifnum \c@secnumdepth >-2\relax
      \refstepcounter{part}%
      \addcontentsline{toc}{part}{\thepart\hspace{1em}#1}%
    \else
      \addcontentsline{toc}{part}{#1}%
    \fi
    \markboth{}{}%
    {\centering
     \interlinepenalty \@M
     \normalfont
     \ifnum \c@secnumdepth >-2\relax
       \partname\nobreakspace\thepart
       \par
        \vspace{1ex}
        \hrule
        \vspace{2ex}
     \fi
     \Huge \bfseries #2\par}%
    \@endpart}

\renewcommand\section{\@startsection {section}{1}{\z@}%
{-3.5ex \@plus -1ex \@minus -.2ex}%
{2.3ex \@plus.2ex}%
{\normalfont\Large\bfseries\clearpage}}
