// Portions Copyright (c) 2006 - 2008, Clark & Parsia, LLC. <http://www.clarkparsia.com>
// Clark & Parsia, LLC parts of this source code are available under the terms of the Affero General Public License v3.
//
// Please see LICENSE.txt for full license terms, including the availability of proprietary exceptions.
// Questions, comments, or requests for clarification: licensing@clarkparsia.com

package com.mycompany.ontodebugger;

import java.util.Iterator;
//import openllet.jena.PelletReasonerFactory;
import org.apache.jena.ontology.OntClass;
import org.apache.jena.ontology.OntModel;
import org.apache.jena.rdf.model.InfModel;
import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.rdf.model.Resource;
import org.apache.jena.reasoner.Reasoner;
import org.apache.jena.reasoner.ValidityReport;
import org.apache.jena.vocabulary.RDFS;

/**
 * An example to show how to use PelletReasoner as a Jena reasoner. The reasoner can be directly attached to a plain RDF <code>Model</code> or attached to an
 * <code>OntModel</code>. This program shows how to do both of these operations and achieve the exact same results.
 *
 * @author Evren Sirin
 */
public class PelletJenaTest
{
	public static void main(final String[] args)
	{
            usageWithOntModel();
		usageWithDefaultModel();

		
	}

	public static void usageWithDefaultModel()
	{
		System.out.println("Results with plain RDF Model");
		System.out.println("----------------------------");
		System.out.println();

		// ontology that will be used
		final String ont = "http://protege.cim3.net/file/pub/ontologies/koala/koala.owl#";
		final String ns = "http://protege.stanford.edu/plugins/owl/owl-library/koala.owl#";

		// create Pellet reasoner
		final Reasoner reasoner =  null;//PelletReasonerFactory.theInstance().create();

		// create an empty model
		final Model emptyModel = ModelFactory.createDefaultModel();

		// create an inferencing model using Pellet reasoner
		final InfModel model = ModelFactory.createInfModel(reasoner, emptyModel);

		// read the file
		model.read(ont);

		// print validation report
		final ValidityReport report = model.validate();
		printIterator(report.getReports(), "Validation Results");

		// print superclasses
		final Resource c = model.getResource(ns + "MaleStudentWith3Daughters");
		printIterator(model.listObjectsOfProperty(c, RDFS.subClassOf), "All super classes of " + c.getLocalName());

		System.out.println();
	}

	public static void usageWithOntModel()
	{
		System.out.println("Results with OntModel");
		System.out.println("---------------------");
		System.out.println();

		// ontology that will be used
		final String ont = "http://protege.cim3.net/file/pub/ontologies/koala/koala.owl#";
		final String ns = "http://protege.stanford.edu/plugins/owl/owl-library/koala.owl#";

		// create an empty ontology model using Pellet spec
		final OntModel model = null;//ModelFactory.createOntologyModel(PelletReasonerFactory.THE_SPEC);

		// read the file
		model.read(ont);

		// print validation report
		final ValidityReport report = model.validate();
		printIterator(report.getReports(), "Validation Results");

		// print superclasses using the utility function
		final OntClass c = model.getOntClass(ns + "MaleStudentWith3Daughters");
		printIterator(c.listSuperClasses(), "All super classes of " + c.getLocalName());
		// OntClass provides function to print *only* the direct subclasses 
		printIterator(c.listSuperClasses(true), "Direct superclasses of " + c.getLocalName());

		System.out.println();
	}

	public static void printIterator(final Iterator<?> i, final String header)
	{
		System.out.println(header);
		for (int c = 0; c < header.length(); c++)
			System.out.print("=");
		System.out.println();

		if (i.hasNext())
			while (i.hasNext())
				System.out.println(i.next());
		else
			System.out.println("<EMPTY>");

		System.out.println();
	}
}
