package chain;

import handler.OrcCommander;
import handler.OrcOfficer;
import handler.OrcSoldier;
import handler.RequestHandler;
import request.Request;

public class OrcKing {
    private RequestHandler chain;

    public OrcKing() {
        buildChain();
    }

    private void buildChain() {
        chain = new OrcCommander(new OrcOfficer(new OrcSoldier(null)));
    }

    public void makeRequest(Request req) {
        chain.handleRequest(req);
    }
}
