package Model;

import java.util.ArrayList;
import java.util.List;

public class Models {

    private final List<Model> data;

    public Models() {
        data = new ArrayList<>();
        data.add( new Model("Vp", "Fnatic", 13, 7));
        data.add( new Model("Navi", "Liquid", 13, 5));
        data.add( new Model("Mouse", "Faze",12,13 ));
        data.add( new Model("Heroic", "Apex",10,13 ));
        data.add( new Model("C9", "Renegedes",8,13 ));
    }   

    public List<Model> getData() {
        return data;
    }
     public void addData(Model model) {
        data.add(model);
    }
     public void addMatch(Model match) {
        data.add(match);
    }
    public void removeData(int index) {
        if (index >= 0 && index < data.size()) {
            data.remove(index);
        }
    }
    
}
