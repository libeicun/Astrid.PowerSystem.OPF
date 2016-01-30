extern char* strfleft(char* string,char separator);
/*�ú��������ַ���string�ĵ�һ��separator���������䱾����ߵ����ַ�����
stringΪ�����ַ�����separatorΪ�ָ�����
��string�в���separator���򷵻�Դ�ַ���string��
��separatorΪstring���׸��ַ����򷵻ؿ��ַ�����
��stringΪ���ַ������򷵻ؿ��ַ�����*/
extern char* strlleft(char* string,char separator);
/*�ú��������ַ���string�����һ��separator���������䱾����ߵ����ַ�����
stringΪ�����ַ�����separatorΪ�ָ�����
��string�в���separator���򷵻�Դ�ַ���string��
��separatorΪstring���׸��ַ����򷵻ؿ��ַ�����
��stringΪ���ַ������򷵻ؿ��ַ�����*/

extern char* strfright(char* string,char separator);
/*�ú��������ַ���string�ĵ�һ��separator���������䱾���ұߵ����ַ�����
stringΪ�����ַ�����separatorΪ�ָ�����
��string�в���separator���򷵻�Դ�ַ���string��
��separatorΪstring��ĩ���ַ����򷵻ؿ��ַ�����
��stringΪ���ַ������򷵻ؿ��ַ�����*/

extern char* strlright(char* string,char separator);
/*�ú��������ַ���string�����һ��separator���������䱾���ұߵ����ַ�����
stringΪ�����ַ�����separatorΪ�ָ�����
��string�в���separator���򷵻�Դ�ַ���string��
��separatorΪstring��ĩ���ַ����򷵻ؿ��ַ�����
��stringΪ���ַ������򷵻ؿ��ַ�����*/
extern char*  strfleft(const char* string,const char separator);
extern char*  strlright(const char* string,const char separator);
extern bool strincludechrs(const char* string,const char* substring);
/*�ú����ж������ַ�����ƥ������
��substring�������ַ���������string�ڣ�����Ϊ��ƥ�䡱�����򷵻�true�����򷵻�false��
�����ַ�����ͬ������true��
��substringΪ���ַ���������true��
��stringΪ���ַ�����substring���ǿ��ַ���������false��*/

extern bool strsubstr(const char* string,const char* substring);
/*�ú����ж������ַ����İ�����ϵ��
��substring������string���򷵻�true�����򷵻�false��
�����ַ�����ͬ������true��
��substringΪ���ַ���������false��
��stringΪ���ַ�����substring���ǿ��ַ���������false��*/


extern char* strdelchr(char* string,char ch);
/*�ú�����string�ڲ����ַ�ch��ɾ���״γ����ߡ�����ɾ��Ŀ�����ַ�����
��ch��������string�ڣ������κβ���������Դ�ַ�����
*/

extern char* strdelchrs(char* string,char ch);
/*�ú�����string�ڲ����ַ�ch��ɾ������ch������ɾ��Ŀ�����ַ�����
��ch��������string�ڣ������κβ���������Դ�ַ�����
*/

extern char* strdelstr(char* string,const char* substring);
/*�ú�����string�ڲ����ַ���substring��ɾ���״γ����ߡ�����ɾ��Ŀ�����ַ�����
��substring��������string�ڣ������κβ���������Դ�ַ�����
*/

extern char* strdelstrs(char* string,const char* substring);
/*�ú�����string�ڲ����ַ���substring��ɾ������substring������ɾ��Ŀ�����ַ�����
��substring��������string�ڣ������κβ���������Դ�ַ�����
*/

extern char* strdeln(char* string,int index);
/*�ú���ɾ��string�ڵ�index����0��ʼ�����ַ�������ɾ��Ŀ�����ַ�����
��index�����ַ������ȣ������κβ���������Դ�ַ�����
*/

extern char* strdelbn(char* string,int index);
/*�ú���ɾ��string�ڵ�����index����0��ʼ�����ַ�������ɾ��Ŀ�����ַ�����
��index�����ַ������ȣ������κβ���������Դ�ַ�����
*/
extern char* strreverse(char* string);
/*�ú�����ת�ַ���string�������ط�ת����ַ�����
��stringΪ���ַ��������ؿ��ַ�����*/
extern int   strmid(const char* string,const char* substring);
/*�ú�����string�ڲ������ַ���substring�������״γ����ߵĶ�Ӧ�ַ������±ꡣ
��δ�ҵ�������-1��
��substringΪ���ַ���������0.
*/
