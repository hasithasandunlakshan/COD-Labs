public  Army() {
        this.troops = new String[5];
        int gold = 500;
        DataBase dataBase = new DataBase();
        Scanner scanner = new Scanner(System.in);
        int k = 0;
        System.out.println("CREATE YOUR ARMY [\"Archer\",\"Knight\",\"Mages\",\"Healer\",\"Mythical\"]");
        String [] category={"Archer","Knight","Mages","Healer","Mythical"};
        while (k < 5) {
            System.out.println("Select soldier:"+ k);
            String soldierName = scanner.nextLine();
            Equipment equipment = new Equipment(soldierName);

            Soldier sol=new Soldier(soldierName,category[k]);

            if (sol.price <= gold  &&  gold>=0 ) {
                if(sol.category==category[k]){
                    troops[k] = soldierName;
                    gold=gold-sol.price;
                    System.out.println("Added " + soldierName + " to the army.   "+gold);
                    k++;

                }
                else{
                    System.out.println("Wrong Category Add from  "+ category[k]);
                    k=k;
                }

            } else {
                System.out.println("Not enough gold to hire " + soldierName);
                System.out.println("RE CREATE THE ARMY");
                k=0;
                gold=500;
                this.troops = new String[5];
            }
        }
        System.out.println("Your Army  ");

        System.out.println(String.join(" ", troops));


        scanner.close();

    }
