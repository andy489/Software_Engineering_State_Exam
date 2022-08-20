package handler;

import request.Request;
import request.RequestType;

public class OrcSoldier extends RequestHandler {
    public OrcSoldier(RequestHandler handler) {
        super(handler);
    }

    public void handleRequest(Request req) {
        if (RequestType.COLLECT_TAX.equals(req.getRequestType())) {
            printHandling(req);
            req.markHandled();
        } else {
            super.handleRequest(req);
        }
    }

    @Override
    public String toString() {
        return "Orc soldier";
    }
}
