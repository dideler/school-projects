<%@ taglib uri="/WEB-INF/lib/reports_tld.jar" prefix="rw" %> 
<%@ page language="java" import="java.io.*" errorPage="/rwerror.jsp" session="false" %>
<%@ page contentType="text/html;charset=ISO-8859-1" %>
<!--
<rw:report id="report"> 
<rw:objects id="objects">
<?xml version="1.0" encoding="WINDOWS-1252" ?>
<report name="Report2-popular_titles_of_all_time" DTDVersion="9.0.2.0.10">
  <xmlSettings xmlTag="MODULE2" xmlPrologType="text">
  <![CDATA[<?xml version="1.0" encoding="&Encoding"?>]]>
  </xmlSettings>
  <reportHtmlEscapes>
    <afterPageHtmlEscape>
    <![CDATA[<hr size=5 noshade>
]]>
    </afterPageHtmlEscape>
    <beforeFormHtmlEscape>
    <![CDATA[<html dir=&Direction>
<body bgcolor="#ffffff">
<form method=post action="_action_">
<input name="hidden_run_parameters" type=hidden value="_hidden_">
<font color=red><!--error--></font>
<center>
<p><table border=0 cellspacing=0 cellpadding=0>
<tr>
<td><input type=submit></td>
<td width=15>
<td><input type=reset></td>
</tr>
</table>
<p><hr><p>
]]>
    </beforeFormHtmlEscape>
    <pageNavigationHtmlEscape>
    <![CDATA[<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html dir=&Direction>
<head>
<meta http-equiv="Content-Type"  content="text/html; charset=&Encoding">
<TITLE>Oracle HTML Navigator</TITLE>
<SCRIPT type="text/javascript" LANGUAGE = "JavaScript">

var jump_index = 1			// Jump to this page
var num_pages = &TotalPages			// Total number of pages
var basefilename = "&file_name"		// Base file name
var fileext = "&file_ext"		//File extension

/* jumps to "new_page" */
function new_page(form, new_page)
{
	form.reqpage.value = new_page;
	parent.frames[0].location = basefilename + "_" + new_page + "."+fileext;
}

/* go back one page */
function back(form)
{
	/* if we are not in first page */
	if (jump_index > 1)
	{
		jump_index--;
		new_page(form, jump_index);
	}
}

/* go forward one page */
function forward(form)
{
	/* if we are not in last page */
	if (jump_index < num_pages)
	{
		jump_index++;
		new_page(form, jump_index);
	}
}

/* go to first page */
function first(form)
{
	if(jump_index != 1)
	{
		jump_index = 1;
		new_page(form, jump_index);
	}
}

/* go to last page */
function last(form)
{
	if(jump_index != num_pages)
	{
		jump_index = num_pages;
		new_page(form, jump_index);
	}
}

/* go to the user specified page number */
function pagenum(form)
{
	/* sanity check */
	if (form.reqpage.value < 1)
	{
		form.reqpage.value = 1;
	}
	if (form.reqpage.value > num_pages)
	{
		form.reqpage.value = num_pages;
	}
	jump_index = form.reqpage.value;
	new_page(form, jump_index);
}
</SCRIPT>
</HEAD>

<BODY>
<FORM NAME="ThisForm" action="" onSubmit="pagenum(this); return false;">
<center><table><tr>
<td> <INPUT TYPE="button"  VALUE="<< " onClick="first(this.form)">
<td> <INPUT TYPE="button"  VALUE=" < " onClick="back(this.form)">
<td> <INPUT TYPE="button"  VALUE="Page:" onClick="pagenum(this.form)">
<td> <INPUT NAME="reqpage" VALUE="1" SIZE=2>
<td> <INPUT TYPE="button"  VALUE=" > " onClick="forward(this.form)">
<td> <INPUT TYPE="button"  VALUE=" >>" onClick="last(this.form)">
</table></center>
</FORM>
</body></html>]]>
    </pageNavigationHtmlEscape>
  </reportHtmlEscapes>
  <data>
    <dataSource name="Q_1">
      <select canParse="no">
      <![CDATA[--select top 5 most popular titles
select *
from( --sum the counts for movies in different transactions
	select title as "Top 5 titles of all time", sum("Total transactions") as "Total transactions"
	from ( --union of rented, pvpurchase and nmpurchase totals
		select rm.title, count(*) as "Total transactions"
		from rental r, rmcopies rm
		where (r.rmcid = rm.rmcid)
		group by rm.title
		union all
		select nm.title, count(*) --per customer per transaction
		from nmpurchase nm
		group by nm.title
		union all
		select rm.title, count(*)
		from rmcopies rm
		where rm.purchased is not null
		group by rm.title
		order by title desc)
	group by title
	order by "Total transactions" desc)
where rownum <= 5;]]>
      </select>
      <displayInfo x="1.65002" y="1.00000" width="0.69995" height="0.19995"/>
      <group name="G_ACCID">
        <displayInfo x="1.45007" y="1.94995" width="1.09998" height="0.79956"
        />
        <dataItem name="Top_5_titles_of_all_time" datatype="vchar2"
         columnOrder="12" width="50" defaultWidth="100000"
         defaultHeight="10000" columnFlags="33"
         defaultLabel="Top 5 Titles Of All Time">
          <dataDescriptor expression="Top 5 titles of all time"
           descriptiveExpression="Top 5 titles of all time" order="1"
           width="50"/>
          <dataItemPrivate adtName="" schemaName=""/>
        </dataItem>
        <dataItem name="Total_transactions_" oracleDatatype="number"
         columnOrder="11" width="22" defaultWidth="20000"
         defaultHeight="10000" columnFlags="33"
         defaultLabel="Total Transactions">
          <dataDescriptor expression="Total transactions"
           descriptiveExpression="Total transactions" order="2"
           oracleDatatype="number" width="22" scale="-127"/>
          <dataItemPrivate adtName="" schemaName=""/>
        </dataItem>
      </group>
    </dataSource>
  </data>
  <layout>
  <section name="main">
    <body>
      <frame name="M_G_ACCID_GRPFR">
        <geometryInfo x="0.00000" y="0.00000" width="3.25000" height="0.37500"
        />
        <generalLayout verticalElasticity="variable"/>
        <visualSettings fillPattern="transparent"
         fillBackgroundColor="r100g100b100"/>
        <repeatingFrame name="R_G_ACCID" source="G_ACCID"
         printDirection="down" minWidowRecords="1" columnMode="no">
          <geometryInfo x="0.00000" y="0.18750" width="3.25000"
           height="0.18750"/>
          <generalLayout verticalElasticity="expand"/>
          <visualSettings fillPattern="transparent"
           fillBackgroundColor="TableCell"/>
          <field name="F_Top_5_titles_of_all_time"
           source="Top_5_titles_of_all_time" minWidowLines="1" spacing="0"
           alignment="start">
            <font face="helvetica" size="10"/>
            <geometryInfo x="0.00000" y="0.18750" width="2.00000"
             height="0.18750"/>
            <generalLayout verticalElasticity="expand"/>
          </field>
          <field name="F_Total_transactions_" source="Total_transactions_"
           minWidowLines="1" spacing="0" alignment="center">
            <font face="helvetica" size="10"/>
            <geometryInfo x="2.06250" y="0.18750" width="1.18750"
             height="0.18750"/>
            <generalLayout verticalElasticity="expand"/>
          </field>
        </repeatingFrame>
        <frame name="M_G_ACCID_HDR">
          <geometryInfo x="0.00000" y="0.00000" width="3.25000"
           height="0.18750"/>
          <advancedLayout printObjectOnPage="allPage"
           basePrintingOn="anchoringObject"/>
          <visualSettings fillPattern="transparent"
           fillBackgroundColor="TableHeading"/>
          <text name="B_Top_5_titles_of_all_time" minWidowLines="1">
            <textSettings spacing="0"/>
            <geometryInfo x="0.00000" y="0.00000" width="2.00000"
             height="0.18750"/>
            <visualSettings fillBackgroundColor="r25g50b75"/>
            <textSegment>
              <font face="helvetica" size="10" bold="yes"
               textColor="r100g100b100"/>
              <string>
              <![CDATA[Top 5 Titles Of All Time]]>
              </string>
            </textSegment>
          </text>
          <text name="B_Total_transactions_" minWidowLines="1">
            <textSettings spacing="0"/>
            <geometryInfo x="2.06250" y="0.00000" width="1.18750"
             height="0.18750"/>
            <visualSettings fillBackgroundColor="TableHeading"/>
            <textSegment>
              <font face="helvetica" size="10" bold="yes"
               textColor="r100g100b100"/>
              <string>
              <![CDATA[Tot. Transactions]]>
              </string>
            </textSegment>
          </text>
        </frame>
      </frame>
    </body>
    <margin>
      <image name="B_1_SEC2" templateSection="main">
        <geometryInfo x="0.50000" y="0.31250" width="1.40625" height="0.37500"
        />
        <visualSettings fillPattern="transparent" fillBackgroundColor="black"
         linePattern="transparent" lineBackgroundColor="black"/>
        <points>
          <point x="0.00000" y="0.00000"/>
          <point x="1.40625" y="0.37500"/>
          <point x="0.50000" y="0.31250"/>
          <point x="1.40625" y="0.37500"/>
        </points>
        <binaryData encoding="hexidecimal" dataId="image.B_1_SEC2">
          
74946483 93167800 42007F00 00FFFFFF 5689BC23 56899D5E 2F2BCC5E C82B8DF6
E9EC5F9F CFCE2F9F 598BBDF9 FBFDCB2D 8E875A2D FCFDFE28 BA5D2ECE 5F8A5C2E
5C8DCEF3 F6E9CC9D 5E2F5F9F 2B5C8D27 598BF7F9 FB5ECE2F C88A5C85 28BA992B
CCFBFCFD 9D2ECE56 C82BC487 5A5ACB2D 26598C85 B8EB2C2D 2EC4F72B 26292C53
86B9F327 5A25588B 84B7EACC CDCE0000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
00000000 00000000 00000000 00129F40 00000000 00C20000 00007800 42000080
FF003080 C1840B0A 1C388031 A2C58C01 16802172 40844106 2250A868 8133E043
07000874 0030A061 8F830A0C 143040A3 E7400408 0E8C5912 90E7C69B 05102859
83172589 820624EC F90438A0 51801A0A 2859C080 A18B9C27 123870B2 96A0C794
2B0ECC68 C158E74C 0315386D FA0617A0 C1090A0E 00F82550 E20F8B00 BAAC6A30
9AA7C893 0FA63C3A F514C4CC 016BFE7D 1B70C001 47000018 0E8BE111 81C40400
24252887 1EE45C94 750AD518 E06086E8 0F850A10 0B6162AF 4FB4AF7E 8500D0A0
21039B19 9A205A05 F3EB628C 43DAC509 651DABC5 99A56E75 90215240 D9041E32
17DA3164 B6D3D00A CE6C28B6 D3E16184 00760628 1DD635EC D29308CD 80A4FBE4
FF898616 5258C0E1 E3808F0E 1B200FF0 5C37E40B 0E183070 90516970 83B00E04
7E2890C7 48040040 2181BDA4 90418100 E5408287 BD00A060 0F153850 A3030C58
40810A06 46145602 0C789FDA 441C70F1 E5000878 F1A00ACD 74E1A980 0C602080
724118CF 10001648 10810F6D D850EF44 1218F2DF 810C3811 E4883E19 60035249
60922609 3940F127 05185002 4A8D10E4 71800E18 74D1C78C EDC8104D 80004083
630B21F8 40AF8E0A 7424219A 0A1974A3 87060581 4A8E51E4 D5E78318 9851C782
3E7403AA 8E1150C4 688141D8 B2D10C08 2810E995 46E4D62B 9B6A3AF6 A4A176E8
1DD75D7E 78C71E41 8A507141 761498B2 5D920CD9 E712AB25 10A06579 864826A7
FF4CA618 0185A042 E486A486 BE0900C2 0116DAF5 D8AA76E4 C46C8752 0092A1A0
046920C6 05A9AAF1 DCA40ABA B2D2A502 7800C08A 0640E153 0A0E76B2 9FA50230
07EDA366 4866A650 56C89399 ADCA74C1 4A81F974 BE270FC6 898394B1 005B5E21
899220E0 448A296B 7DE74F08 6850FEAF 2D108031 8C0CB5F3 D4092697 83D6A214
C7822AA0 04E92860 531CCBF1 14B2B6BA 9313C11A 105040C1 12FBAF6E 8923E853
64AE1540 B2B0582A 00024E42 C67A0009 8FEA3900 84C152E4 1F11A6C2 E422300A
F2FBF15E A17A3001 F3079E68 B29CCE19 AC406291 451B2000 DB25A86F 200EEE40
B100D414 A8B520A1 2659F125 C123EBBA 29CF3530 D0F19900 4C337DD8 361001B5
FFD63648 8DE7424F 78023001 F2BBE1D0 E7182BE1 0ADB1460 2181AC6B 00E6B749
4F2D14D1 04085BC8 6CAB2120 A08ED108 30CD2E4E 730090A2 81B65009 7A8A5E60
3F23BE63 600564E4 433B52A7 D0081D21 C1BF6718 9082983D 202AFEBD 1D5830C1
83006D3D 2EA46618 9969BF59 8BA06ABB 2D3FF8E7 4D048022 480DCF48 1249032C
7ED0B80A 20E49A31 8183E425 F7BE97E4 A08CDB25 BF6024AD 3E4FFDEF 44F75A80
ACF00058 0CAF8010 20040CBD 43080850 40BC0011 85ABFA83 0018C43F 88108080
E2C9C205 75F51600 20308831 D0220908 93930C40 908CFAB0 6CAC382C 311E7058
70085041 02101BA1 1ED60100 1871630D 3230080E F421040C 64950118 83920010
FF938000 500207E4 B2950C70 14893930 29075271 46004C27 8C43E122 0903B213
2E11F328 00B2A5F0 0080811E 01172F0C 0005BE04 1102066A E0471C02 E6150840
427D74A1 0F6140C2 1138831B 2690F384 446A9315 78F1970C 21B00B00 50870998
F11D2EA0 1A8F44C1 2F7CE810 06AC00A6 4D6C5980 19082CB5 02FB020F 5C23201F
72A2CD3E 70FD7E11 51E70FB8 A4CB3E21 1B8F1934 230752E4 4A6D008A 5C009320
080049CF 4E74A689 08F2200E 292C3600 782D8F1C 0AC10549 804300ED E3279C15
232559F1 CBD8A29F 593433E7 46004515 0446A009 B444A050 29CA4036 00C69008
30C21172 26A40023 118E3C42 AA25C471 4866004A 9774A663 210093CF 8440A181
FF08E62E 11827082 364F2593 72B2A731 0025CF8C 102A71F4 40AF23C8 FEC76E70
D593F4C9 8811181D BA6AC2BF 9E114084 293AE19A 4A13D392 CBB42FB8 8970D004
B3F7877C A0A74C0A B44B7E70 903F0071 AE2F5A77 C93962FA 96DCF1AF 317253C2
0410C39D 3447E421 98264C90 10D79074 55AB1559 B2575ED0 98937AA6 220F63A7
4E9ED6E7 902DB5ED 49BA0DCB 1A05419A 4D00823F 72D0DFA6 33FE82CB 70801D00
5542026B A10F0430 8200266E CB765337 240CF9A5 25E9BC40 ACF1BCAA 254B243F
9A0550B0 4290884C 0A82273A D55C76F5 B9AFFC5B E707D714 1F021630 0C4D4BE1
4D2BB441 B68098A9 05DA0A4B 7A2954DA 75BBA225 F808679A B2114E70 D5A00080
074A4399 873FC656 5E9A6C0A 404FE8C0 025693D6 BF148CAC 5E29E756 6AA296B4
CD356C6F 6BCE469E D111B2F4 60C20A64 70810040 E2A38C80 0675BBCD D0082062
9308456F 39CB8152 FA229CB3 942AE559 DB3007FA 871EB314 8FED1FAB AE5862C7
5EBCBDEF AF7FFB00 E00B0870 C406ED60 4000B3DC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC DCDCDCDC
DCDCDCDC DCDCDCDC DCDCDCDC DCDCDFDF
        </binaryData>
      </image>
      <text name="B_OR$BODY_SECTION" minWidowLines="1">
        <textSettings spacing="0"/>
        <geometryInfo x="0.52051" y="0.75000" width="3.16699" height="0.16675"
        />
        <textSegment>
          <font face="Courier New" size="10" bold="yes"/>
          <string>
          <![CDATA[Top 5 most popular titles of all time]]>
          </string>
        </textSegment>
      </text>
    </margin>
  </section>
  </layout>
  <colorPalette>
    <color index="190" displayName="TextColor" value="#336699"/>
    <color index="191" displayName="TableHeading" value="#336699"/>
    <color index="192" displayName="TableCell" value="#e0f0ff"/>
    <color index="193" displayName="Totals" value="#c5e3ff"/>
  </colorPalette>
  <reportPrivate defaultReportType="tabular" versionFlags2="0"
   templateName="rwblue" sectionTitle="Top 5 most popular titles of all time"
  />
  <reportWebSettings>
  <![CDATA[]]>
  </reportWebSettings>
</report>
</rw:objects>
-->

<html>

<head>
<meta name="GENERATOR" content="Oracle 9i Reports Developer"/>
<title> Your Title </title>

<rw:style id="yourStyle">
   <!-- Report Wizard inserts style link clause here -->
</rw:style>

</head>


<body>

<rw:dataArea id="yourDataArea">
   <!-- Report Wizard inserts the default jsp here -->
</rw:dataArea>



</body>
</html>

<!--
</rw:report> 
-->
