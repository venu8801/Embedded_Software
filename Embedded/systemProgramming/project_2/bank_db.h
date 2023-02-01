/* header file for bank server and client contains
 * all the structure definitions common to server and client*/
 
 
 
struct dob_user
{
	unsigned char dd;
       unsigned char mm;
	unsigned char yy;


};
struct addr_user
{

	char cty[32];


};
struct nominee_user
{
	char nom_name[32];
	struct dob_user nom_dob;
	unsigned long int adh_no;
	

};

struct profile_user
{
	
	unsigned char opt;
	
	unsigned int balanc;

	char u_name[32];

	char gen;

	unsigned int u_id;

	char pass[16];

	unsigned long int ac_no;
	
	unsigned long int adh_no;
	
	unsigned long int ph_no;

	struct dob_user u_dob;

	struct addr_user u_addr;

	struct nominee_user u_nominee;

	//struct reg_user u_reg;


};

//------fucntion prototypes
int init_db(void);
 int create_user(struct profile_user);
